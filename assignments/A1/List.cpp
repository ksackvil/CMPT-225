/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - List has a maximum capcity of MAX_ELEMENTS.
 * Table of Contents: 
 * 		- CONSTRUCTOR - line 23
 * 		- GETTERS     - line 34
 * 		- OPPERATIONS - line 52
 * 		- HELPERS     - line 191
 * 
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#include <iostream>
#include "List.h"

using namespace std;

// ---------- CONSTRUCTOR ---------- // 

// Default constructor
List::List()
{
    // initialize values
    elementCount = 0;
    // capcity is the number of available slots
    capacity = MAX_ELEMENTS;
}

// ---------- GETTERS ---------- // 

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
    return(elementCount);
}

// Description: Returns a pointer to element at the index
Patient* List::valueAt(int index)
{
    Patient *returnPtr;

    returnPtr = &elements[index];

    return(returnPtr);
}

// ---------- OPPERATIONS ---------- // 

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement)
{   
    bool wasAdded = false;
    bool patientExists = false;

    // check if list is full
    if(elementCount == 5)
    {
        wasAdded = false;
    }
    else
    {
        // iterate to see if card number already exists
        for(int it = 0; it < elementCount; it++)
        {
            if(newElement.getCareCard() == elements[it].getCareCard())
            {
                patientExists = true;
                break;
            }
        }

        // add patient if valid
        if(!patientExists)
        {
            elements[elementCount] = newElement;
            elementCount++;
            wasAdded = true;
        }
    }
    
    return(wasAdded);
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved )
{
    Patient newElements[MAX_ELEMENTS];  // Empty copy of elements array
    int newIt = 0;                      // iterator for the new elements copy
    int newElementCount = elementCount; // copy of elemtentCount to prevent mutation
    bool wasRemoved = false;

    // Copy elements to new elements
    //      IF element[it] is the patient we want to remove do not copy over patient to
    //      new copy, do not increment newElementCount iterator
    for(int it = 0; it < elementCount; it++)
    {
        if(elements[it].getCareCard() == toBeRemoved.getCareCard())
        {
            newElementCount--; //stay at current element
            wasRemoved = true;
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

    return(wasRemoved);
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

// Description: Prints elements of list in assending order by care card number.
// 				Uses recursiveQuickSort as a helper.
void List::printAll() 
{
    // sort elements before printing
    recursiveQuickSort(elements, 0, elementCount-1);

    for(int it = 0; it < elementCount; it++)
    {  
        cout << elements[it];
    }
}

// ---------- HELPERS ---------- // 

// Description: Implements a simple recursive quicksort algorithm on given patients array
// Precondition: patients must be an array of type Patients, start must be the index
//				 of the first element, end must be the index of the last.
// Postcondition: given patients array will now be sorted in assending order by 
//       		 care card number.    
void List::recursiveQuickSort(Patient patients[], int start, int end)
{
    int pivot = end; //always choose last element as pivot

    // these will be our lhs and rhs cursors, set default values of
    // rhs -> end and lhs -> start 
    int left = start;
    int right = end;

    
    while(left <= right)
    {
        // moving the lhs cursor
        while(patients[pivot] > patients[left])
        {
            left++;
        }
        // moving the rhs cursor
        while(patients[right] > patients[pivot])
        {
            right--;
        }

        // If they haven't passed eachother "in correct places" swap left element
        // with right.
        if(left <= right)
        {
            // create copy of right element as a temp element
            Patient tempPatient(patients[right].getCareCard());
            tempPatient.setName(patients[right].getName());
            tempPatient.setAddress(patients[right].getAddress());
            tempPatient.setPhone(patients[right].getPhone());
            tempPatient.setEmail(patients[right].getEmail());

            // swap
            patients[right] = patients[left];
            patients[left] = tempPatient;

            // move the cursor one more
            right--;
            left++;
        }
    }

    // while valid continue to quick sort each partition
    if(right > start)
    {
        // lhs partition
        recursiveQuickSort(patients, start, right);
    }
    if (left < end)
    {
        // rhs partition
        recursiveQuickSort(patients, left, end);
    }
}

// Description: Checks if an element in list has a care card matching given card number
// Postcondition: Boolen value will inform user if element with matching care card exists. 
bool List::cardExists(string cardNumber) const
{
    bool patientExists = false;

    // iterate elements searching for matching number
    for(int it = 0; it < elementCount; it++)
    {
        if(cardNumber == elements[it].getCareCard())
        {
            patientExists = true;
            break;
        }
    }

    return(patientExists);
}