#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;

class HuffmanTree 
{
    private:
        TreeNode * root;
        void printRecursive(TreeNode *node);
        void destroyTree(TreeNode * subTreeRoot);
        void encodeRecursive(TreeNode * node, char letter, string &path, bool &found);
        void compressTreeRecursive(TreeNode * node, string &compTree, bool &done);
        TreeNode * decompressTreeRecursive(string compTree, int &current);

    public:
        HuffmanTree();
        HuffmanTree(HuffNode rootData); 
        HuffmanTree(HuffmanTree * rootTree);
        HuffmanTree(HuffmanTree * leftTree, HuffmanTree * rightTree);
        ~HuffmanTree();

        int getRootFrequency();
        void print();
        string encode(char letter);
        string decode(string bitMap);
        string compressTree();
        void decompressTree(string compTree);
};