/* 
 * HuffNode.cpp
 *
 * Description: 
 *      This class stores the necessary data for Huffmans algorithm, specifically each char/letter
 *      And its frequency.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include "HuffNode.h"

// Des: Default constructor
HuffNode::HuffNode()
{
    frequency = 0;
    letter = 0;
}

// Des: Parameterized constructor
// Post node will be build with initialLetter and initalFrequency
HuffNode::HuffNode(int initialLetter, int initialFrequency)
{
    letter = initialLetter;
    frequency = initialFrequency;
}