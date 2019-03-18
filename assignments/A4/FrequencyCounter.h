/* 
 * FrequencyCounter.h
 *
 * Description: 
 *      This class handles the to building and manipulation of  a frequency table 
 *      that stores the frequency with which a char appears in a file.
 *
 * Class Invariant: 
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include <string>
#include "HuffNode.h"

using namespace std;

class FrequencyCounter 
{
    private:
        static const int MAX_ELEMENTS = 256;
        HuffNode * elements;
        int numElements;

    public:
        FrequencyCounter();
        ~FrequencyCounter();
        void build(string inputText);
        void push(char newLetter);
        HuffNode valueAt(int index);
        int getNumElements();

};