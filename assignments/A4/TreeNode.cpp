
#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode()
{
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(HuffNode startData, TreeNode * startLeft, TreeNode * startRight)
{
    data = startData;
    left = startLeft;
    right = startRight;
}