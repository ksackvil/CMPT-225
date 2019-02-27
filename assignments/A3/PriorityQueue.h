/*
 * PriorityQueue.h
 *
 * Description: Template class PriorityQueue, implemented using a linked list
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 * Editted by: Kai Sackville-Hii
 *
 */

 /* None of the current content of this file can be modified. */

#pragma once
#include <cstdio>  // Needed for NULL
#include <iostream> 
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std;

/******* PriorityQueue Public Interface - START - *******/
template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

   Node<T>* head;      // Pointer to first node in the chain
   int elementCount;   // Current count of list items

/* You can add private methods to this class */

public:

   // ---------- CONSTRUCTORS ---------- //

   // Default Constructor
   PriorityQueue();

   // Copy Constructor
   PriorityQueue(const PriorityQueue& rhsPriorityQueue);

   // Destructor
   ~PriorityQueue();

   // ---------- QUEUE OPPERATIONS ---------- //

   // Description: Returns the number of elements in the Priority Queue.
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
   // Time Efficiency: O(n)
   bool enqueue(const T& newElement);

   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   T peek() const throw(EmptyDataCollectionException);

   // ---------- HELPERS ---------- //

   // To deal with the warning regarding template and friend function: 
   // I used the first "Introvert" solution described in 
   // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
   // The idea: only declare a particular instantiation of the << operator as a friend
   // by inlining the operator.  
   // Description: Overload << opperator. For debugging purposes, outputs 
   //              each Event object.
   // Postcondition: Each Event objects data will be pretty printed.
   friend ostream & operator<< (ostream & os, const PriorityQueue<T>& rhs) {
      Node<T>* current = rhs.head;

      os << "elementCount = " << rhs.elementCount;
      
      // Traverse the list
      while (current != NULL){
         cout << current -> data; // Print data
         current = current -> next; // Go to next Node
      }

      return os;
   } // end of operator <<
};
/******* PriorityQueue Public Interface - END - *******/

/******* PriorityQueue Implementation - START - *******/
// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue()
{
    head = NULL;
    elementCount = 0;
}

// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhsPriorityQueue)
{
   // copy elements count
   elementCount = rhsPriorityQueue.elementCount;

   // make sure head is not null
	if(rhsPriorityQueue.head != NULL)
	{
		// create temp iter point to new node and point temp head to that
		Node<T> *tempCurrent = new Node<T>;	
		Node<T> *tempHead = tempCurrent;

		// point current to head
		Node<T> *current = rhsPriorityQueue.head;

		// copy data 
		tempCurrent->data = current->data;

		// move to next current node 
		current = current->next;
		
		while(current != NULL)
		{
			// add node and move to it
			tempCurrent->next = new Node<T>;
			tempCurrent = tempCurrent->next;
			
			// copy over data
			tempCurrent->data = current->data;
			
			// move to next node
			current = current->next;
		}	

		// head now points to temp head aka our copied queue
		head = tempHead;
	}
}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
   Node<T> *current = head;

   while(current != NULL)
   {
      // move to next and delete old
      current = current->next;
      delete head;
      head = current;
   }
}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
template <class T>
int PriorityQueue<T>::getElementCount() const
{
    return(elementCount);
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const
{
   if(elementCount==0)
   {
      return true;
   }
   else 
   {
      return false;
   }
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class T>
bool PriorityQueue<T>::enqueue(const T& newElement)
{
   Node<T> *newNode = new Node<T>;

   // add in new nodes data
   newNode->data = newElement;
   newNode->next = NULL;

   // if the list is empty than simply add new node to head, else need to add in sorted
   // order
   if(head == NULL)
   {
      head = newNode;
   }
   else
   {
      Node<T> *current = NULL;
      Node<T> *previous = NULL;

      current = head;

      while(current != NULL)
      {  

         // Simplest case: new node is higher priority, add in before current node.
         if(newNode->data < current->data) 
         {
            // if previous is NULL (no where to add)
            if(elementCount == 1 || current == head)
            {
               newNode->next = current;
               head = newNode;
               break;
            }
            else
            {
               newNode->next = current;
               previous->next = newNode;
               break;
            }      
         }
         // Base case: new node is lowest priority, add to end of queue.
         else if(current->next == NULL)
         {
            current->next = newNode;
            break;
         }

         // set previous to current and move current down list
         previous = current;
         current = current->next;
      }
   }

   elementCount++;
   return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue()
{
   if(elementCount != 0)
   {
      Node<T> *delNode = NULL;

      delNode = head;
      head = delNode->next;

      delete delNode;
      elementCount--;
      
      return true;
   }
   else
   {
      return false;
   }
}

// Description: Returns the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException)
{
    if(elementCount == 0)
    {
        throw EmptyDataCollectionException("PriorityQueue.cpp peek()");
    }
    else
    {
        return(head->data);
    }
    
}
/******* PriorityQueue Implementation - END - *******/
