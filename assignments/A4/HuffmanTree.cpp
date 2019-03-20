/* 
 * HuffmanTree.cpp
 *
 * Description: 
 *      This class handles the tree opperations of the Huffman tree, specifically
 *      it provides operations to build/rebuild the Huffman tree, to compute the
 *      Huffman code of a given character, and to obtain the character given a Huffman code.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include "HuffmanTree.h"
#include "TreeNode.h"
#include "HuffNode.h"
#include <string>

// ============================ RECURSIVE IMPLEMENTATIONS ============================ //

// Des: Recursive helper of print
void HuffmanTree::printRecursive(TreeNode *node)
{
    if (node != NULL)
    {
        /* first recur on left child */
        printRecursive(node->left);

        /* then print the data of node */
        cout << (char)node->data.letter << node->data.frequency;

        /* now recur on right child */
        printRecursive(node->right);
    }
}

// Des: Recursive helper of deconstructor
// Post: Tree will be destroyed
void HuffmanTree::destroyTree(TreeNode *subTreeRoot)
{
    if (subTreeRoot != NULL)
    {
        destroyTree(subTreeRoot->left);
        destroyTree(subTreeRoot->right);
        subTreeRoot = NULL;
        delete subTreeRoot;
    }
}

// Des: Recursive helper of encode
// Pre: found indicates if the letter has been found.
// Post: path will be updated with letters code
void HuffmanTree::encodeRecursive(TreeNode *node, int letter, char *&path, bool &found, int &current)
{

    if (node->left != NULL && !found)
    {
        path[current] = '0';
        current++;
        encodeRecursive(node->left, letter, path, found, current);
    }

    if (node->right != NULL && !found)
    {
        path[current] = '1';
        current++;
        encodeRecursive(node->right, letter, path, found, current);
    }

    if (node->data.letter == letter && !found)
    {
        found = true;
    }

    if (!found)
    {
        current--;
    }
}

// Des: Recursive helper of compressTree
// Pre: done indicates base case when recursion is done.
// Post: compTree will be updated with compressed tree string
void HuffmanTree::compressTreeRecursive(TreeNode *node, char *&compTree, bool &done, int &current)
{
    done = false;

    if (node->left != NULL)
    {
        if (!done)
        {
            compTree[current] = '0';
            current++;
        }
        compressTreeRecursive(node->left, compTree, done, current);
    }

    if (node->right != NULL)
    {
        if (!done)
        {
            compTree[current] = '0';
            current++;
        }
        compressTreeRecursive(node->right, compTree, done, current);
    }

    // When not a leaf
    if (node->right == NULL && node->left == NULL)
    {
        compTree[current] = '1';
        current++;
        compTree[current] = node->data.letter;
        current++;
        done = true;
    }
}

// Des: Recursive helper of decompressTree
TreeNode *HuffmanTree::decompressTreeRecursive(string compTree, int &current)
{
    if (compTree[current] == '1')
    {
        current++;
        HuffNode leafData = HuffNode(compTree[current], 0);
        TreeNode *leaf = new TreeNode(leafData, NULL, NULL);
        return (leaf);
    }
    else
    {
        current++; 
        HuffNode emptyData; //New sub tree root

        // Build left child 
        TreeNode *leftChild;
        leftChild = decompressTreeRecursive(compTree, current);
        current++;

        // Build right child
        TreeNode *rightChild;
        rightChild = decompressTreeRecursive(compTree, current);

        // build sub tree
        return (new TreeNode(emptyData, leftChild, rightChild));
    }
}

// Des: Recursive helper of getBitSize
// Pre: found indicates base case when recursion is done
// Post: count is incremented with height of node with letter when found
void HuffmanTree::getBitSizeRecursive(TreeNode *node, char letter, bool &found, int &count)
{   
    // Move left
    if (node->left != NULL && !found)
    {
        count++;
        getBitSizeRecursive(node->left, letter, found, count);
    }

    // Move right
    if (node->right != NULL && !found)
    {
        count++;
        getBitSizeRecursive(node->right, letter, found, count);
    }

    // If we have found the letter
    if (node->data.letter == letter && !found)
    {
        found = true;
    }

    // move back up a node if not found and on leaf ie decrement count
    if (!found)
    {
        count--;
    }
}

// =================================================================================== //

// Des: Default constructor
HuffmanTree::HuffmanTree()
{
    root = NULL;
}

// Des: Parameterized constructor 1
// Pre: rootData contains the data for the root of the new tree
// Post: A new tree will be built with the rootData as the root data.
HuffmanTree::HuffmanTree(HuffNode rootData)
{
    root = new TreeNode(rootData, NULL, NULL);
}

// Des: Parameterized constructor 2
// Pre: rootTree must be a Huffman tree
// Post: root will point to root tree, ie rootTree will be coppied
HuffmanTree::HuffmanTree(HuffmanTree *rootTree)
{
    root = new TreeNode(rootTree->root->data, NULL, NULL);
}

// Des: Parameterized constructor 3
// Pre: left and right tree must be Huffman trees.
// Post: root will have leftTree as its left child and rightTree as its right
HuffmanTree::HuffmanTree(HuffmanTree *leftTree, HuffmanTree *rightTree)
{
    // if not a leaf 
    if (leftTree->root != NULL && rightTree->root != NULL)
    {
        int addedFrequency = 0;
        addedFrequency = leftTree->root->data.frequency + rightTree->root->data.frequency;
        HuffNode rootData('\0', addedFrequency);

        root = new TreeNode(rootData, leftTree->root, rightTree->root);
    }
}

// Des: Deconstructor
HuffmanTree::~HuffmanTree()
{
    destroyTree(root);
}

// Des: Gets the HuffNode frequency from root
// Post: frequency of root will be returned
int HuffmanTree::getRootFrequency()
{
    return (root->data.frequency);
}

// Des: Gets number of bits required for a letters huffman code
// Post: number of bits for letter will be returned
int HuffmanTree::getBitSize(char letter)
{
    bool found = false; // base case flag for recursion
    int count = 0;      // inital bit size count

    getBitSizeRecursive(root, letter, found, count);

    return count;
}

// Des: Prints tree in order
void HuffmanTree::print()
{
    printRecursive(root);
}

// Des: Yields Huffman code for given letter
// Pre: letter is the char to encode, path is the returned Huffman code
//      passed by reference and current is the iterator for where to push to in
//      path also by reference
// Post: path will be updated with letters huffman code if found.
void HuffmanTree::encode(char letter, char *&path, int &current)
{
    bool found = false; // base case flag for recursion
    encodeRecursive(root, letter, path, found, current);
}

// Des: Traverses tree following the bitMap (Huffman Code) for a letter.
// Pre: The huffman tree should already be built in order to traverse it
// Post: A string containing the decoded bitmap will be returned.
string HuffmanTree::decode(string bitMap)
{
    string decodedString = ""; // string to be returned containing decoded bits
    int index = 0;             // itr for bitMap
    TreeNode *current = root;  // start at root node

    while (index <= bitMap.size())
    {
        // if at a leaf grab leafs letter
        if (current->left == NULL && current->right == NULL)
        {
            decodedString.push_back(current->data.letter);
            current = root;
        }
        // else continue decoding, 0 means go left, 1 means go right
        else
        {
            if (bitMap[index] == '0')
            {
                current = current->left;
            }
            else if (bitMap[index] == '1')
            {
                current = current->right;
            }

            index++;
        }
    }

    return decodedString;
}

// Des: Compresses tree in an in order fashion
// Pre: compTree is the compressed tree to edit, current is the iterator identifiing
//      where to push to in compTree.
// Post: Traverse the tree in order, for each non-leaf node push '0' for each leaf push
//       '1' then its letter.
void HuffmanTree::compressTree(char *&compTree, int &current)
{
    bool done = false;
    compressTreeRecursive(root, compTree, done, current);
}

// Des: Decompresses tree in an in order fashion.
// Pre: compTree is the tree string encoded using this.compressTree format.
// Post: Tree matching the given compTree string will be built.
void HuffmanTree::decompressTree(string compTree)
{
    int current = 0;
    root = decompressTreeRecursive(compTree, current);
}
