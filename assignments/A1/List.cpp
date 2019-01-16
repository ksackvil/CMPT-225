/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#include <iostream>
#include "List.h"

using namespace std;

// Default constructor
List::List()
{
    // initialize values
    elementCount = 0;
    // capcity is the number of available slots
    capacity = MAX_ELEMENTS;
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
    return(elementCount);
}

Patient* List::valueAt(int index)
{
    Patient *returnPtr;

    returnPtr = &elements[index];

    return(returnPtr);
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement)
{
    elements[elementCount] = newElement;
    elementCount++;
    
    return(true);
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved )
{
    // 
    Patient newElements[MAX_ELEMENTS];  // Empty copy of elements array
    int newIt = 0;                      // iterator for the new elements copy
    int newElementCount = elementCount; // copy of elemtentCount to prevent mutation

    // Copy elements to new elements
    //      IF element[it] is the patient we want to remove do not copy over patient to
    //      new copy, do not increment newElementCount iterator
    for(int it = 0; it < elementCount; it++)
    {
        if(elements[it].getCareCard() == toBeRemoved.getCareCard())
        {
            newElementCount--; //stay at current element
        }
        else
        {
            newElements[newIt] = elements[it];
            newIt++; // move to next element 
        }
    } 

    // Copy newElements to elements
    //      newElements has our object array without the toBeRemoved object.
    //      Replacing elements with newElements object array essentially "removes" the
    //      desired object.
    for(int it = 0; it < newElementCount; it++)
    {
        elements[it] = newElements[it];
    }

    // New elements, update elementCount
    elementCount = newElementCount; 

    return(true);
}

// Description: Remove all elements.
void List::removeAll()
{
    Patient tempElements[MAX_ELEMENTS]; // Create empty array

    // Replace element[it] with the empty value of tempElements[it],
    // aka removing all the elements.
    for(int it = 0; it < MAX_ELEMENTS; it++)
    {
        elements[it] = tempElements[it];
    }

    // No elements, update elementCount 
    elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) 
{
    Patient *returnedPtr; // Ptr to target object
    bool found = false;   // Flag determing if ptr will be returned

    // Search for element with same careCard as target, if found point returnedPtr
    // to the address of the element. 
    for(int it = 0; it < MAX_ELEMENTS; it++)
    {
        if(target.getCareCard() == elements[it].getCareCard())
        {
            returnedPtr = &elements[it];
            found = true;
        }
    }
    
    // if there exists target within elements return the pointer otherwise return NULL
    if(found)
    {
        return(returnedPtr);
    }
    else
    {
        return(NULL);
    }
}

void List::printAll() 
{
    for(int it = 0; it < elementCount; it++)
    {
        cout << elements[it];
    }
}