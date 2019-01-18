/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - List has a maximum capcity of MAX_ELEMENTS.
 *
 * Table of Contents: 
 * 		- CONSTRUCTOR - line 54
 * 		- GETTERS     - line 59
 * 		- OPPERATIONS - line 67
 * 		- HELPERS     - line 90
 *  
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:

/* 
 * You can add more attributes to this class, 
 * but you cannot remove the attributes below 
 * nor can you change them.
 */

	static const int MAX_ELEMENTS = 5; // Small capacity so can test when data collection becomes full
	                                   // ***As we are testing the code of our assignment, we can  
	                                   //    change the value given to this constant.***
	Patient elements[MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
	int elementCount;                  // Current element count in element array
	int capacity;                      // Actual maximum capacity of element array   

public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// ---------- CONSTRUCTOR ---------- // 

	// Default constructor
	List();

	// ---------- GETTERS ---------- // 

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Returns a pointer to element at the index
	Patient* valueAt(int index);

	// ---------- OPPERATIONS ---------- // 

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	// Description: Prints elements of list in assending order by care card number.
	// 				Uses recursiveQuickSort as a helper.
	void printAll(); 

	// ---------- HELPERS ---------- // 
   
	// Description: Implements a simple recursive quicksort algorithm on given patients array
	// Precondition: patients must be an array of type Patients, start must be the index
	//				 of the first element, end must be the index of the last.
	// Postcondition: given patients array will now be sorted in assending order by 
	//       		 care card number.    
	void recursiveQuickSort(Patient patients[], int start, int end);

	// Description: Checks if an element in list has a care card matching given card number
	// Postcondition: Boolen value will inform user if element with matching care card exists. 
	bool cardExists(string cardNumber) const;

}; // end List.h