/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
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

   // Default Constructor
   PriorityQueue();

   // Copy Constructor
   PriorityQueue(const PriorityQueue& rhsPriorityQueue);

   // Destructor
   ~PriorityQueue();

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
   T& peek() const throw(EmptyDataCollectionException);

   template <typename U>
   friend ostream& operator<<(ostream& os, const PriorityQueue<U>& p);

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

}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
   Node<T> *current = head;

   while(current != NULL)
   {
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

   newNode->data = newElement;
   newNode->next = NULL;

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

         if(newNode->data < current->data) 
         {
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
         else if(current->next == NULL)
         {
            current->next = newNode;
            break;
         }

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
T& PriorityQueue<T>::peek() const throw(EmptyDataCollectionException)
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

template <typename U>
ostream& operator<<(ostream& os, const PriorityQueue<U>& p)
{
   Node<U> *current = NULL;
   current = p.head;

   while(current != NULL)
   {
      Event e = current->data;
      os << endl 
         << " | " << e.getType() <<  " | " << e.getTime() <<  " | " << e.getLength() << " | "
         << endl;

      current = current -> next;
   }
     
   return os;
}
/******* PriorityQueue Implementation - END - *******/
