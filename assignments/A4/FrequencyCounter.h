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
#include "HuffNode.h"

using namespace std;

class FrequencyCounter 
{
    private:
        static const int MAX_ELEMENTS = 256; // total of 256 possibilities (ASCII key coding)
        HuffNode * elements;                 // array of HuffNodes with letter and frequency
        int numElements;                     // total number of elements in array elements. 

    public:

        // Des: Default constructor
        FrequencyCounter();

        // Des: Deconstructor
        ~FrequencyCounter();

        // Des: builds frequency table off of an input string
        // Pre: inputText must be the string to run frequency analysis on
        // Post: Elements array will be build in no particular order, numElements will
        //       be updated.
        void build(string inputText);

        // Des: Pushes new char to array of elements.
        // Post: If an element exists with the same letter as newLetter then add one to its 
        //       frequency else add new element.
        void push(char newLetter);

        // Des: Gives the value of elements in given index
        // Pre: index must be in the range 0 <= index <= numElements
        // Post: Huffnode at index will be returned
        HuffNode valueAt(int index);

        // Des: Gets the number of elements.
        // Post: numElements will be returned.
        int getNumElements();
};