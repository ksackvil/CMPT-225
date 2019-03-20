/* 
 * HuffmanTree.h
 *
 * Description: 
 *      This class handles the tree opperations of the Huffman tree, specifically
 *      it provides operations to build/rebuild the Huffman tree, to compute the
 *      Huffman code of a given character, and to obtain the character given a Huffman code.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;

class HuffmanTree 
{
    private:
        TreeNode * root; // root of the linked based tree

        // ============================ RECURSIVE IMPLEMENTATIONS ============================ //

        // Des: Recursive helper of print
        void printRecursive(TreeNode *node);

        // Des: Recursive helper of deconstructor
        // Post: Tree will be destroyed
        void destroyTree(TreeNode * subTreeRoot);

        // Des: Recursive helper of encode
        // Pre: found indicates if the letter has been found.
        // Post: path will be updated with letters code
        void encodeRecursive(TreeNode * node, int letter, char* &path, bool &found, int &current);

        // Des: Recursive helper of compressTree
        // Pre: done indicates base case when recursion is done.
        // Post: compTree will be updated with compressed tree string
        void compressTreeRecursive(TreeNode * node, char* &compTree, bool &done, int &current);

        // Des: Recursive helper of decompressTree
        TreeNode * decompressTreeRecursive(string compTree, int &current);

        // Des: Recursive helper of getBitSize
        // Pre: found indicates base case when recursion is done
        // Post: count is incremented with height of node with letter when found
        void getBitSizeRecursive(TreeNode * node, char letter, bool & found, int & count);

        // =================================================================================== //

    public:

        // Des: Default constructor
        HuffmanTree();

        // Des: Parameterized constructor 1
        // Pre: rootData contains the data for the root of the new tree
        // Post: A new tree will be built with the rootData as the root data.
        HuffmanTree(HuffNode rootData); 

        // Des: Parameterized constructor 2
        // Pre: rootTree must be a Huffman tree
        // Post: root will point to root tree, ie rootTree will be coppied
        HuffmanTree(HuffmanTree * rootTree);

        // Des: Parameterized constructor 3
        // Pre: left and right tree must be Huffman trees.
        // Post: root will have leftTree as its left child and rightTree as its right
        HuffmanTree(HuffmanTree * leftTree, HuffmanTree * rightTree);

        // Des: Deconstructor
        ~HuffmanTree();

        // Des: Gets the HuffNode frequency from root
        // Post: frequency of root will be returned
        int getRootFrequency();

        // Des: Gets number of bits required for a letters huffman code
        // Post: number of bits for letter will be returned
        int getBitSize(char letter);

        // Des: Prints tree in order
        void print();

        // Des: Yields Huffman code for given letter
        // Pre: letter is the char to encode, path is the returned Huffman code 
        //      passed by reference and current is the iterator for where to push to in
        //      path also by reference
        // Post: path will be updated with letters huffman code if found.
        void encode(char letter, char* &path, int &current);

        // Des: Traverses tree following the bitMap (Huffman Code) for a letter.
        // Pre: The huffman tree should already be built in order to traverse it
        // Post: A string containing the decoded bitmap will be returned.
        string decode(string bitMap);

        // Des: Compresses tree in an in order fashion
        // Pre: compTree is the compressed tree to edit, current is the iterator identifiing 
        //      where to push to in compTree.
        // Post: Traverse the tree in order, for each non-leaf node push '0' for each leaf push
        //       '1' then its letter.
        void compressTree(char* &compTree, int &current);

        // Des: Decompresses tree in an in order fashion.
        // Pre: compTree is the tree string encoded using this.compressTree format.
        // Post: Tree matching the given compTree string will be built.
        void decompressTree(string compTree);
};