/* 
 * Event.h
 *
 * Description: 
 * 
 * Class Invariant: FIFO or LILO order
 *
 * Author: Kai Sackville-Hii
 * Date: 
 */

#pragma once
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <string>

using namespace std;

/******* Queue Public Interface - START - *******/
template <class ElementType>
class Queue 
{
    private: 
        static unsigned const INITIAL_SIZE = 6;
        ElementType *elements;
        unsigned elementCount;  // number of elements in the queue
        unsigned capacity;      // number of cells in the array
        unsigned frontIndex;    // index the topmost element
        unsigned backIndex;     // index where the next element will be placed

        bool resize(unsigned newCapacity);

    public:
        Queue();

        // Description: Returns "true" is this Queue is empty, otherwise "false".
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(const ElementType& newElement);
        
        // Description: Removes the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure) and  
        //              returns "true" if successful, otherwise "false".
        // Precondition: This Queue is not empty.
        // Time Efficiency: O(1)
        bool dequeue();
        
        // Description: Returns the element located at the "front" of this Queue.
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const throw(EmptyDataCollectionException);  

        template <typename U>
        friend ostream& operator<<(ostream& os, const Queue<U>& p);
};  
/******* Queue Public Interface - END - *******/

/******* Queue Implementation - START - *******/
template <class ElementType>
bool Queue<ElementType>::resize(unsigned newCapacity)
{
    // Map class vars to temps
    unsigned tempFrontIndex = frontIndex;
    unsigned tempBackIndex = backIndex;
    unsigned copy_count = 0;
    
    // Create copy array with the new capacity
    ElementType *elements_copy = new ElementType [newCapacity];
    
    // This loop will copy elements to the elements_copy in order from 
    // front to back. So elements[frontIndex] will be set first element of and 
    // copied over until back index. ie: front index will be 0 and back 
    // index will be capacity+1
    do
    {
        elements_copy[copy_count] = elements[tempFrontIndex];
        tempFrontIndex = (tempFrontIndex + 1) % capacity;
        copy_count++;
    } while (tempFrontIndex != tempBackIndex); 

    // Set class vars.
    // Note that back index must be set before capacity since backIndex will be 
    // set to the old value of capacity.
    backIndex = capacity;
    frontIndex = 0;
    elements = elements_copy;
    capacity = newCapacity; 
    
    delete [] elements_copy;
    return true;
} 

// Desc:  Constructor
template <class ElementType>
Queue<ElementType>::Queue()
{
    elementCount = 0;
    capacity = INITIAL_SIZE;
    frontIndex = 0;
    backIndex = 0;
    elements = new ElementType [INITIAL_SIZE]; // Dynamic array
} // constructor

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const 
{
    return elementCount == 0;
} // isempty

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement) 
{
    // check if the array is full
    if(elementCount == capacity)
    {
        resize(capacity*2);
    }

    // Push new element to the back of circular array,
    // move back index and increment element count.
    elements[backIndex] = newElement;
    backIndex = (backIndex+1) % capacity;
    elementCount++;

    return true;

} // enqueue


// Description: Removes the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure) and  
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::dequeue() 
{
    // if after removeing another element the array is less than 25% full, halve the capacity.
    if( (float)(elementCount-1) / float(capacity) < 0.25 && (capacity/2) >= INITIAL_SIZE)
    {
        resize(capacity/2);
    }

    frontIndex = (frontIndex + 1) % capacity;
    elementCount--;
    return true;
} // dequeue

template <class ElementType>
ElementType& Queue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
    if(elementCount == 0)
    {
        throw EmptyDataCollectionException("Queue.h peek()");
    }
    else
    {
        return(elements[frontIndex]);
    }
}

template <typename U>
ostream& operator<<(ostream& os, const Queue<U>& p)
{
    if(p.elementCount == 0)
    {
        os << "\nQueue is empty\n";
    }
    else
    {
        // copy old array to new one
        for(int el=0; el < p.capacity; el++)
        {
            if(el == p.frontIndex)
            {
                os << "f:" << p.elements[el];  
            }
            else if(el == p.backIndex)
            {
                os << "b: " << p.elements[el];
            }
            else
            {
                os << el << ": " << p.elements[el];           
            }
        }
    }

    return os;
}
/******* Queue Implementation - END - *******/