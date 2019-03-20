/* 
 * QNode.h
 *
 * Description: 
 *    This class stores the HuffmanTrees used for the priority queue. Each QNode holds one HuffmanTree
 *    and has a pointer to the next tree in the priority queue.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>
#include "HuffmanTree.h"

using namespace std;

class QNode 
{
    public:
        HuffmanTree data; // Tree data
        QNode * next;     // ptr to next QNode in queue

        // Des: Default constructor
        QNode();

        // Des: Parameterized constructor
        QNode(HuffmanTree newData, QNode * newNext);
};