/* 
 * InBitStream.h
 *
 * Description: 
 *      This class handles the opperation of read a sequence of bits from the given
 *      istream. 
 *
 * Class Invariant: 
 *      Will only read unsigned chars in binary form, ie: will only deal with ones
 *      and zeros. The member numBits must be a int between 0 and 7.
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>

using namespace std;

class InBitStream
{
    private:
        unsigned char buf; // Bit buffer, will be mutated. When full will be flushed.
        int numBits;       // Number of bits read, buffer is full when this == 7 (aka 8 bits)
        istream & in;      // In stream to read from 
        
    public:

        // Des: Parameterized constructor.
        // Pre: os must be an opened file in binary mode, encoded by the class OutBitStream
        InBitStream(istream & is);

        // Des: Reads single bit to buf
        // Post: Leftmost bit will be returned, numBits will be incremented buff will be shifted left.
        int readBit();

        // Des: Fills buff with byte from file
        // Post: Buff will be a full byte, numBits will == 0
        void fill();
};