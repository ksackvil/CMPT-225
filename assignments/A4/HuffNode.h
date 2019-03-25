/* 
 * HuffNode.h
 *
 * Description: 
 *      This class stores the necessary data for Huffmans algorithm, specifically each char/letter
 *      And its frequency.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>

using namespace std;
 
class HuffNode 
{
    public:
        int letter;    // ASCII letter integer rep
        int frequency; // The frequency count of letter

        // Des: Default constructor
        HuffNode();

        // Des: Parameterized constructor
        // Post node will be build with initialLetter and initalFrequency
        HuffNode(int initialLetter, int initialFrequency);
};