
#pragma once
#include <iostream>

using namespace std;
 
class HuffNode 
{
    public:
        int letter;
        int frequency;
        HuffNode();
        HuffNode(int initialLetter, int initialFrequency);
};