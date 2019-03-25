/* 
 * OutBitStream.cpp
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

#include "OutBitStream.h"
#include <iostream>

using namespace std;

// Des: Parameterized constructor.
// Pre: os must be an opened file in binary mode.
OutBitStream::OutBitStream(ostream & os): out(os)
{
    buf = '\0';
    numBits = 7;    
}

// Des: Writes single bit to buf
// Pre: inputBit can only be 1 or zero.
void OutBitStream::writeBit(int inputBit) 
{
    if(numBits < 0) 
    {   
        flush();
    }   

    buf |= (inputBit << numBits); 
    numBits--;
}

// Des: Writes buff to out.
// Post: buf will be reset to '\0' and numBits to 7
void OutBitStream::flush() 
{
    out.write((char*)&buf, sizeof(buf));
    buf = '\0';
    numBits = 7;
}
