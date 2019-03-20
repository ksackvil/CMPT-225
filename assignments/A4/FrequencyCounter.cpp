/* 
 * FrequencyCounter.h
 *
 * Description: 
 *      This class handles the building and manipulation of a frequency table 
 *      that stores the frequency with which a char appears in a file.
 *
 * Class Invariant: 
 *      elements array cannot have more than 256 elements.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include <string>
#include "FrequencyCounter.h"
#include "HuffNode.h"

using namespace std;

// Des: Default constructor
FrequencyCounter::FrequencyCounter()
{
    elements = new HuffNode[MAX_ELEMENTS];
    numElements = 0;
}

// Des: Deconstructor
FrequencyCounter::~FrequencyCounter()
{
    delete[] elements;
}

// Des: builds frequency table off of an input string
// Pre: inputText must be the string to run frequency analysis on
// Post: Elements array will be build in no particular order, numElements will
//       be updated.
void FrequencyCounter::build(string inputText)
{
    for (int i = 0; i < inputText.size(); i++)
    {
        push(inputText[i]);
    }
}

// Des: Pushes new char to array of elements.
// Post: If an element exists with the same letter as newLetter then add one to its
//       frequency else add new element.
void FrequencyCounter::push(char newLetter)
{
    bool exists = false;  // Flag to see if elment was added
    int newFrequency = 1; // starting freq

    for (int i = 0; i < numElements; i++)
    {
        // if the letter already exists add one to its freq
        if (elements[i].letter == newLetter)
        {
            newFrequency += elements[i].frequency;
            elements[i].frequency = newFrequency;
            exists = true;
        }
    }

    // add new element
    if (!exists)
    {
        HuffNode newNode(newLetter, newFrequency);
        elements[numElements] = newNode;
        numElements++;
    }
}

// Des: Gives the value of elements in given index
// Pre: index must be in the range 0 <= index <= numElements
// Post: Huffnode at index will be returned
HuffNode FrequencyCounter::valueAt(int index)
{
    return elements[index];
}

// Des: Gets the number of elements.
// Post: numElements will be returned.
int FrequencyCounter::getNumElements()
{
    return numElements;
}