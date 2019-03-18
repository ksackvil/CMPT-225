
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
    // ifstream inFile("./test_inputs/Muppets.txt", ios::binary | ios::ate);

    // cout << inFile.tellg() << endl;
    // InBitStream I(inFile);

    // char bit1;
    // int bit2;

    // inFile.get(bit1);
    // bit2 = I.readBit();

    // cout << bit1 << " bit1\n" 
    //  << bit2 << endl;


    // TESTING ================================

    string command = argv[1];
    string fileToWrite = argv[3];
    string fileToRead = argv[2];
    ifstream inFile(fileToRead, ifstream::binary);
    ofstream outFile(fileToWrite, ofstream::binary);
    int inFileBytes = 0;

    if (inFile.is_open())
    {
        if (command == "-c")
        {
            // Initialize vars
            char inFileChar = '\0';
            string inFileString = "";

            // Initialize objects
            FrequencyCounter fq;
            PriorityQueue q;
            OutBitStream b(outFile);

            string encodedTree = "";

            // Read in each char of file to compress.
            while (inFile.get(inFileChar))
            {
                inFileString.push_back(inFileChar); // push char to string
                inFileBytes++;                      // char takes up 1 byte (8 bits) so increment for every char
            }

            cout << fileToRead << " -> " << inFileBytes << " bytes" << endl;

            // Build the frequency table based off of the input files string
            fq.build(inFileString);

            // Build the initial priority queue of huffman trees using frequency table
            for (int i = 0; i < fq.getNumElements(); i++)
            {
                // convert frequency table node to a tree leaf
                HuffmanTree *newEl = new HuffmanTree(fq.valueAt(i));

                // add in priority order
                q.enqueue(newEl);
            }

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
            }

            HuffmanTree OptimizedTree(q.peek());

            // Generate the Huffman byte for each char in file
            for (int i = 0; i < inFileString.size(); i++)
            {
                encodedTree.append(OptimizedTree.encode(inFileString[i]));
            }

            // write the encoded tree as the first line of the file
            // cout << encodedTree << endl;
            outFile << OptimizedTree.compressTree() << " ";
            // OptimizedTree.print();
            // cout << endl;
            for (int i = 0; i < encodedTree.size(); i++)
            {
                int bit = encodedTree[i] - '0';
                b.writeBit(bit);
            }

            // write final byte then close file.
            b.flush();
            outFile.close();
        }
        else if (command == "-d")
        {
            HuffmanTree newTree;
            char inFileChar = '\0';
            char previousChar = '\0';
            int bit = 0;
            string compTree = "";
            string compString = "";



            // Read in each char of file to compress.
            while (!inFile.eof())
            {
                previousChar = inFileChar;
                inFile.get(inFileChar); // get char from file

                if (previousChar != '1' && inFileChar == ' ')
                {
                    cout << compTree << endl;
                    break;
                }
                else
                {
                    compTree.push_back(inFileChar);

                }
                
                inFileBytes++; // char takes up 1 byte (8 bits) so increment for every char
            }

            InBitStream I(inFile);

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

            // last bit will be noise so remove it ie the last BYTE.
            compString = compString.substr(0, compString.size()); 
            
            newTree.decompressTree(compTree);
            newTree.print();
            cout << endl;
            outFile << newTree.decode(compString);

        }
    }
    else
    {
        cout << "ERROR: Could not open input file '" << fileToRead << "'\n";
    }
    

    return 0;
}