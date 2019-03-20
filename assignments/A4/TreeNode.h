/* 
 * TreeNode.h
 *
 * Description: 
 *    This class stores the HuffNodes used for the HuffmanTrees. Each TreeNode holds one HuffData
 *    and has a pointer to its left and right Nodes.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>
#include "HuffNode.h"
 
class TreeNode 
{
    public:
        HuffNode data;    // data with letter and freq
        TreeNode * left;  // left child
        TreeNode * right; // right child

        // Des: Default constructor
        TreeNode();

        // Des: parameterized constructor
        TreeNode(HuffNode startData, TreeNode * startLeft, TreeNode * startRight);
};