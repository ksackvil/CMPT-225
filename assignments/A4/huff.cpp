/* 
 * huff.cpp
 *
 * Description: 
 *      This is the main driver program for the huffman compression application. This code handles
 *      the client interaction for both compressing to .huf files and decompressing.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include <fstream>
#include "OutBitStream.h"
#include "InBitStream.h"
#include "FrequencyCounter.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Make sure there are 4 args inputted
    if (argc != 4)
    {
        cout << "ERROR: invalid command\n\nMust have the form:\n ./huff <command> <target_file> <destination_file>\n\n"
             << "where <command is either -c (compress) or -d (decompress)\n\nterminating program.\n";
        return 1;
    }

    string command = argv[1];     // string containing command
    string fileToWrite = argv[3]; // string containing file name to write to
    string fileToRead = argv[2];  // string containing file name to read from

    // open files to read and write from in binary mode with itr at end to start (so can get size)
    ifstream inFile(fileToRead, ifstream::binary | ios::ate);

    int inFileSize = inFile.tellg(); // Grab the bytes of the in file
    inFile.seekg(0, ios::beg);       // move itr to begining of file

    if (inFileSize <= 0)
    {
        // something went wrong opening the files
        cout << "ERROR: input file '" << fileToRead << "' is 0 bytes, cannot compress.\n";
        return 1;
    }

    if (inFile.is_open())
    {
        if (command == "-c")
        {
            // Initialize vars
            char *memblock;          // contains chars from infile
            char *encodedBits;       // Holds the huffman encoded bits built from infile chars
            char *encodedTree;       // Holds the encoded/compressed tree
            int *intRep;             // Integer representation of the infile chars
            int outputSize = 0;      // calculated size of outFile
            int encodingSize = 0;    // calculated size of bits using huffman encoding
            int encodedBitsSize = 0; // actual size of encoded bits
            int encodedTreeSize = 0; // actual size of encoded tree
            int pqNodeCount = 0;     // number of nodes in priority queue
            int numUniqueChars = 0;  // number of unique characters from in file

            // Initialize objects
            FrequencyCounter fq;
            PriorityQueue q;

            // ========== READ CHAR* FROM FILE ========== //
            memblock = new char[inFileSize]; // create memory for chars from in
            intRep = new int[inFileSize];
            inFile.read(memblock, inFileSize); // read into memblock

            // Display output message
            cout << fileToRead << " -> " << inFileSize << " bytes" << endl;

            // ========== BUILD FREQUENCY TABLE ========== //
            for (int i = 0; i < inFileSize; i++)
            {
                intRep[i] = memblock[i];
                fq.push(intRep[i]);
            }

            // ========== BUILD INITIAL PRIORITY QUEUE ========== //
            // Build the initial priority queue of huffman trees using frequency table
            for (int i = 0; i < fq.getNumElements(); i++)
            {
                // convert frequency table node to a tree leaf
                HuffmanTree *newEl = new HuffmanTree(fq.valueAt(i));

                // add in priority order
                q.enqueue(newEl);
            }

            numUniqueChars = q.getElementCount();

            // ========== HUFFMAN TREE BUILDING ========== //
            // Build Huffman tree from Priority queue leaves
            while (q.getElementCount() > 1 && q.getElementCount() != 0)
            {
                // grab 1st priority leaf
                HuffmanTree *leftSubTree = new HuffmanTree(q.peek());
                q.dequeue();

                // grab 2nd priority leaf
                HuffmanTree *rightSubTree = new HuffmanTree(q.peek());
                q.dequeue();

                // join theses two leaves into a new tree and add this tree to the queue
                HuffmanTree *joinedTree = new HuffmanTree(leftSubTree, rightSubTree);
                q.enqueue(joinedTree);
                pqNodeCount++;
            }

            // we can now calculate the bits needed for the encoded tree
            encodedTreeSize = pqNodeCount + numUniqueChars * 2;

            // ========== ENCODING THE INPUT FILE ========== //
            HuffmanTree OptimizedTree(q.peek()); // Make new tree for optimizing

            // check the output size
            for (int i = 0; i < fq.getNumElements(); i++)
            {
                // Grab the number of bits needed to store the huffman encoded char
                encodingSize = OptimizedTree.getBitSize(fq.valueAt(i).letter);

                // add the encoding size multiplied by its frequency to output size
                outputSize += encodingSize * fq.valueAt(i).frequency;
            }

            encodedBitsSize = outputSize; // Encoded bits will be this output size in bits
            outputSize = outputSize / 8;  // Total output size will be in bytes so / by 8

            // allocate new memory for the encodedBits
            encodedBits = new char[encodedBitsSize];

            int count = 0;

            // Generate the Huffman byte for each char in file
            for (int i = 0; i < inFileSize + 1; i++)
            {
                OptimizedTree.encode(memblock[i], encodedBits, count);
            }

            // ========== WRITE ENCODED TREE TO OUTPUT FILE ========== //
            // write the encoded tree as the first line of the file
            encodedTree = new char[encodedTreeSize];

            int curr = 0; // element marker used for compressTree funct
            string charValues = "";

            OptimizedTree.compressTree(encodedTree, curr);
            outputSize += encodedTreeSize; // add the bytes size of the encoded tree
            outputSize++;                  //add the ' ' char to total size

            // ========== CHECK FILE SIZES ========== //
            if (inFileSize < outputSize)
            {
                cout << "*** Size of compressed file > size of source file ***\n";
                return 1;
            }

            // If output is okay open out file
            ofstream outFile(fileToWrite, ofstream::binary);

            // check if file is opened correctly
            if (!outFile.is_open())
            {
                // something went wrong opening the files
                cout << "ERROR: Could not open output file '" << fileToWrite << "'\n";
                return 1;
            }

            // create bitstream object
            OutBitStream b(outFile);

            for (int i = 0; i < encodedTreeSize; i++)
            {
                outFile << encodedTree[i];
            }

            // Spaceing between encodedTree and bits
            outFile << " ";

            cout << fileToWrite << " -> " << outputSize << " bytes" << endl;

            // ========== WRITE ENCODED BITS TO OUTPUT FILE ========== //
            for (int i = 0; i < encodedBitsSize; i++)
            {
                // convert char to its integer representation
                // this makes sure to convert char '0' -> 0
                // as opposed to converting the char to its ASCII value
                int bit = encodedBits[i] - '0';
                b.writeBit(bit);
            }

            // Write final Byte even if it is not full.
            b.flush();

            // close out file
            outFile.close();
        }
        else if (command == "-d")
        {
            char inFileChar = '\0';   // Char read from in file
            char previousChar = '\0'; // previous char read from in file
            int bit = 0;              // bit read from in file
            string encodedTree = "";  // compressed tree in string form
            string compString = "";   // compressed message in string form

            ofstream outFile(fileToWrite, ofstream::binary);

            // check if file is opened correctly
            if (!outFile.is_open())
            {
                // something went wrong opening the files
                cout << "ERROR: Could not open output file '" << fileToWrite << "'\n";
                return 1;
            }

            // initialize objects
            HuffmanTree newTree;
            InBitStream I(inFile);

            //  ========== READ ENCODED TREE ========== //
            // Read in each char of file to compress.
            while (!inFile.eof())
            {
                previousChar = inFileChar;
                inFile.get(inFileChar); // get char from file

                if (previousChar != '1' && inFileChar == ' ')
                {
                    break;
                }
                else
                {
                    encodedTree.push_back(inFileChar);
                }
            }

            // ========== READ THE HUFFMAN ENCODED BITS ========== //
            while (!inFile.eof())
            {
                bit = I.readBit();

                if (bit == 0)
                {
                    compString.push_back('0');
                }
                else if (bit == 1)
                {
                    compString.push_back('1');
                }
            }

            // ========== DECOMPRESS TREE AND DECODE BITS ========= //
            newTree.decompressTree(encodedTree);

            // ========== WRITE DECODED BITS TO OUTFILE ========== //
            outFile << newTree.decode(compString);

            // close outfile
            outFile.close();
        }
        else
        {
            // Command did not match -c or -d
            cout << "ERROR: invalid command\n\nMust have the form:\n ./huff <command> <target_file> <destination_file>\n\n"
                 << "where <command is either -c (compress) or -d (decompress)\n\nterminating program.\n";
            return 1;
        }

        // Close input file
        inFile.close();
    }
    else
    {
        // something went wrong opening the files
        cout << "ERROR: Could not open input file '" << fileToRead << "'\n";
    }

    return 0;
}