
#include <iostream>
#include "QNode.h"
#include "HuffNode.h"

QNode::QNode()
{
    HuffmanTree emptyTree;
    
    data = emptyTree;
    next = NULL;
}

QNode::QNode(HuffmanTree newData, QNode * newNext)
{
    data = newData;
    next = newNext;
}