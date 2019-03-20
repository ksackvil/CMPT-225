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

#include <iostream>
#include "TreeNode.h"

// Des: Default constructor
TreeNode::TreeNode()
{
    left = NULL;
    right = NULL;
}

// Des: parameterized constructor
TreeNode::TreeNode(HuffNode startData, TreeNode * startLeft, TreeNode * startRight)
{
    data = startData;
    left = startLeft;
    right = startRight;
}