/* 
 * FrequencyCounter.cpp
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
#include "FrequencyCounter.h"
#include "HuffNode.h"

using namespace std;

FrequencyCounter::FrequencyCounter()
{
    elements = new HuffNode[MAX_ELEMENTS];
    numElements = 0;
}

FrequencyCounter::~FrequencyCounter()
{
    delete [] elements;
}

void FrequencyCounter::build(string inputText)
{
    for(int i = 0; i < inputText.size(); i++)
    {
        push(inputText[i]);
    }

    for(int i = 0 ; i < numElements; i++)
    {
        cout << elements[i].letter << " ";
    }
    cout << endl;
}

void FrequencyCounter::push(char newLetter)
{
    bool exists = false;
    int newFrequency = 1;

    for(int i = 0; i < numElements; i++)
    {
        if(elements[i].letter == newLetter) 
        {
            newFrequency += elements[i].frequency;
            elements[i].frequency = newFrequency;
            exists = true;
        }
    }

    if(!exists)
    {
        HuffNode newNode(newLetter, newFrequency);
        elements[numElements] = newNode;
        numElements++;
    }
}

HuffNode FrequencyCounter::valueAt(int index)
{
    return elements[index];
}

int FrequencyCounter::getNumElements()
{
    return numElements;
}