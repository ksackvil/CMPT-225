
#include <iostream>
#include "HuffmanTree.h"
#include "TreeNode.h"
#include "HuffNode.h"
#include <string>

HuffmanTree::HuffmanTree()
{
    root = NULL;
}

HuffmanTree::HuffmanTree(HuffNode rootData)
{
    root = new TreeNode(rootData, NULL, NULL);
}

HuffmanTree::HuffmanTree(HuffmanTree *rootTree)
{
    root = new TreeNode(rootTree->root->data, NULL, NULL);
}

HuffmanTree::HuffmanTree(HuffmanTree *leftTree, HuffmanTree *rightTree)
{
    if (leftTree->root != NULL && rightTree->root != NULL)
    {
        int addedFrequency = 0;
        addedFrequency = leftTree->root->data.frequency + rightTree->root->data.frequency;
        HuffNode rootData('\0', addedFrequency);

        root = new TreeNode(rootData, leftTree->root, rightTree->root);
    }
}

HuffmanTree::~HuffmanTree()
{
    destroyTree(root);
}

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

int HuffmanTree::getRootFrequency()
{
    return (root->data.frequency);
}

void HuffmanTree::printRecursive(TreeNode *node)
{
    if (node != NULL)
    {
        /* first recur on left child */
        printRecursive(node->left);

        /* then print the data of node */
        cout << node->data.letter;

        /* now recur on right child */
        printRecursive(node->right);
    }
}

void HuffmanTree::print()
{
    printRecursive(root);
}

void HuffmanTree::encodeRecursive(TreeNode *node, char letter, string &path, bool &found)
{

    if (node->left != NULL && !found)
    {
        path.append("0");
        encodeRecursive(node->left, letter, path, found);
    }

    if (node->right != NULL && !found)
    {
        path.append("1");
        encodeRecursive(node->right, letter, path, found);
    }

    if (node->data.letter == letter && !found)
    {
        found = true;
    }

    if (!found)
    {
        path = path.substr(0, path.size() - 1);
    }
}

string HuffmanTree::encode(char letter)
{
    string path = "";
    bool found = false;

    encodeRecursive(root, letter, path, found);

    return (path);
}

void HuffmanTree::compressTreeRecursive(TreeNode *node, string &compTree, bool &done)
{
    done = false;

    if (node->left != NULL)
    {
        if (!done)
        {
            compTree.append("0");
        }
        compressTreeRecursive(node->left, compTree, done);
    }

    if (node->right != NULL)
    {
        if (!done)
        {
            compTree.append("0");
        }
        compressTreeRecursive(node->right, compTree, done);
    }

    if (node->right == NULL && node->left == NULL)
    {
        compTree.append("1");
        compTree.push_back(node->data.letter);
        done = true;
    }
}

string HuffmanTree::compressTree()
{
    string compTree = "";
    bool done = false;

    compressTreeRecursive(root, compTree, done);

    return (compTree);
}

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
        HuffNode emptyData;

        TreeNode *leftChild;
        leftChild = decompressTreeRecursive(compTree, current);
        current++;

        TreeNode *rightChild;
        rightChild = decompressTreeRecursive(compTree, current);

        return (new TreeNode(emptyData, leftChild, rightChild));
    }
}

void HuffmanTree::decompressTree(string compTree)
{
    int current = 0;
    root = decompressTreeRecursive(compTree, current);
}

string HuffmanTree::decode(string bitMap)
{
    string decodedString = "";
    int index = 0;
    TreeNode *current = root;

    while (index <= bitMap.size())
    {
        if (current->left == NULL && current->right == NULL)
        {
            decodedString.push_back(current->data.letter);
            current = root;
        }
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
