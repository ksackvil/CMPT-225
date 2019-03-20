/* 
 * InBitStream.cpp
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

#include "InBitStream.h"
#include <iostream>

using namespace std;

// Des: Parameterized constructor.
// Pre: os must be an opened file in binary mode, encoded by the class OutBitStream
InBitStream::InBitStream(istream & is): in(is)
{
    buf = '\0';
    numBits = 0;    
}

// Des: Reads single bit to buf
// Post: Leftmost bit will be returned, numBits will be incremented buff will be shifted left.
int InBitStream::readBit() 
{
    int bit = -1;

    if(numBits == 0 || numBits > 7)
    {
        fill();
    }
    
    bit =  (1 & buf>>(7-numBits));
    numBits++;

    return bit;
}

// Des: Fills buff with byte from file
// Post: Buff will be a full byte, numBits will == 0
void InBitStream::fill() 
{
    // cout << "\nfilling bufffer\n";
    buf = in.get();
    numBits = 0;
}