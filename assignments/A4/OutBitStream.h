/* 
 * InBitStream.cpp
 *
 * Description: 
 *      This class handles the opperation of writing a sequence of bits to the given
 *      ostream. 
 *
 * Class Invariant: 
 *      Will only write unsigned chars in binary form, ie: will only deal with ones
 *      and zeros. The member numBits must be a int between 0 and 7.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>

using namespace std;

class OutBitStream
{
    private:
        unsigned char buf; // Bit buffer, will be mutated. When full will be flushed.
        int numBits;       // Number bits which can be added to buff, buffer is full when this == 0 (aka no more room)
        ostream & out;     // Out stream to write too.
        
    public:

        // Des: Parameterized constructor.
        // Pre: os must be an opened file in binary mode.
        OutBitStream(ostream & os);

        // Des: Writes single bit to buf
        // Pre: inputBit can only be 1 or zero.
        void writeBit(int inputBit);

        // Des: Writes buff to out.
        // Post: buf will be reset to '\0' and numBits to 7
        void flush();
};