/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Kai Sackville-Hii
 * Date: Feb 6, 2019
 */
 
#include "Queue.h"
#include <iostream>
using namespace std;

// Desc:  Constructor
Queue::Queue()
{
    elementCount = 0;
    capacity = INITIAL_SIZE;
    frontindex = 0;
    backindex = 0;
    elements = new int [INITIAL_SIZE]; // Dynamic array
} // constructor

// Desc:  Deconstructor
Queue::~Queue()
{
    // free elements set values to default;
    if(elementCount != 0)
    {
        delete [] elements;
        elementCount = 0;
        frontindex = 0;
        backindex = 0;
    }
} // Deconstructor

// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) 
{
    // check if the array is full
    if(elementCount == capacity)
    {
        // Create copy array double the capacity
        int doubleCapacity = capacity*2;
        int *elements_copy = new int [doubleCapacity];

        // copy old array to new one
        for(int el=0; el<capacity; el++)
        {
            elements_copy[el] = elements[el];
        }

        // set capcity and elements to the newly made copy arr
        capacity = doubleCapacity;
        elements = elements_copy;
    }
    
    // add new element
    elements[backindex] = x;

    // set new values of back index and count
    elementCount++;
    backindex++;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
// Pre:  Queue not empty
void Queue::dequeue() 
{
    if(elementCount != 0)
    {
        int halfCapacity = capacity / 2; 

        // if array is less than 25% full halve the capacity.
        if( (float)elementCount / float(capacity) < 0.25 && halfCapacity >= INITIAL_SIZE)
        {   
            // array with half the capacity as elements
            int *elements_copy = new int [halfCapacity];

            // copy old array to new one
            for(int el=0; el<halfCapacity; el++)
            {
                cout << elements[el] << " ";
                elements_copy[el] = elements[el];
            }

            capacity = halfCapacity;
            elements = elements_copy;
        }
        // remove item from front of queue
        else
        {
            // array to copy to
            int *elements_copy = new int[capacity]; 

            // copy old array to new one
            for(int el=0; el<capacity; el++)
            {
                elements_copy[el-1] = elements[el];               
            }

            // set elements
            elements = elements_copy;
        }
    
        elementCount--;
        backindex--; 
    }
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
// Pre:  Queue not empty
int Queue::peek() const 
{
    return elements[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const 
{
    return elementCount == 0;
} // isempty

// Desc: prints out queue with pretty formating
void Queue::printQueue() const
{
    if(elementCount == 0)
    {
        cout << "\nQueue is empty\n";
    }
    else
    {
        cout << "\n| ";
    
        // copy old array to new one
        for(int el=0; el<elementCount; el++)
        {
            cout << elements[el] << " | ";            
        }
        for(int el=0; el < (capacity-elementCount); el++)
        {
            cout << "x | ";
        }
        cout << endl;
    }
}

