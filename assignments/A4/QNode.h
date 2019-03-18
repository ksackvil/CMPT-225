
#pragma once
#include <iostream>
#include "HuffmanTree.h"

using namespace std;

class QNode 
{
    public:
        HuffmanTree data;
        QNode * next;

        QNode();
        QNode(HuffmanTree newData, QNode * newNext);
};