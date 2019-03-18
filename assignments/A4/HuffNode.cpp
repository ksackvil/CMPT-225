
#include <iostream>
#include "HuffNode.h"

HuffNode::HuffNode()
{
    frequency = 0;
    letter = 0;
}
    
HuffNode::HuffNode(int initialLetter, int initialFrequency)
{
    letter = initialLetter;
    frequency = initialFrequency;
}