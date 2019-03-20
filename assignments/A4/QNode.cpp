/* 
 * QNode.cpp
 *
 * Description: 
 *    This class stores the HuffmanTrees used for the priority queue. Each QNode holds one HuffmanTree
 *    and has a pointer to the next tree in the priority queue.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include "QNode.h"
#include "HuffNode.h"

// Des: Default constructor
QNode::QNode()
{
    HuffmanTree emptyTree;

    data = emptyTree;
    next = NULL;
}

// Des: Parameterized constructor
QNode::QNode(HuffmanTree newData, QNode *newNext)
{
    data = newData;
    next = newNext;
}