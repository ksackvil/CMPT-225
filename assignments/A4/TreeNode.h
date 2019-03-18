
#pragma once
#include <iostream>
#include "HuffNode.h"
 
class TreeNode 
{
    public:
        HuffNode data;
        TreeNode * left;
        TreeNode * right;

        TreeNode();
        TreeNode(HuffNode startData, TreeNode * startLeft, TreeNode * startRight);
};