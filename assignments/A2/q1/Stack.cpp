/* 
 * Stack.cpp
 *
 * Description: 
 *     Implementation of a stack using an int singly linked list in 
 *     which the top of the stack is at the tail of the list
 * 
 * Class Invariant: 
 *     Node in the stack are in LIFO order. Data pushed into nodes
 *     must be of type int. Each not is of type StackNode.
 * 
 *
 * Author: Kai Sackville-Hii 
 * Date: Feb 6, 2019
 */
 
#include <cstddef>  // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

// Desc:  Constructor
// Post:  Stack is empty
Stack::Stack()
{
    head = NULL;
    tail = NULL;
}

// Desc: Deconstructor
// Post: Dynamically allocated heap memory is freed.
Stack::~Stack() 
{   
    // iterator ptr
    StackNode *current = head;

    // free up each node in heap until at end of stack
    while(current != NULL)
    {
        // move current one step ahead
        current = current->next; 

        // free node which head points to, point head to next
        delete head;
        head = current;
    }

    // point to NULL for safety
    head = NULL;
    tail = NULL;
}

// Desc:  Insert element x to the top of the stack.
// Post:  New Node will be created and pushed to the tail of the list (top of stack).
void Stack::push(int x) 
{
    // create new empty node
    StackNode *newNode = new StackNode; 

    // copy over data to new node and point it to null
    newNode->data = x;
    newNode->next = NULL;   

    // if the stack is empty than point to this new node
    if(head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    // else point tail to this new node
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Desc: Remove and return element at the top of the stack.
// Pre: Stack must not be empty
// Post: Node at the top of stack will be popped, tail will point to the next 
//       Node on the stack. The data of the popped node will be returned.
int Stack::pop()
{
    if(head == NULL && tail == NULL)
    {
        cout << "ERROR: cant pop from an empty stack, returning 0\n";
        return(0);
    }
    else
    {
        StackNode *current = head;   // iter for our list
        StackNode *previous = head;  // iter which is one behind current
        int poppedData = 0;          // the data to be returned

        // if the stack has only one element then dont iterate, pop top of stack
        if(head == tail)
        {
            poppedData = tail->data;
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else
        {
            // iterate through stack until end
            while(current->next != NULL)
            {       
                previous = current;
                current = current->next;
            }

            // point tail to the element before one to be removed
            // point next to null
            tail = previous;
            tail->next = NULL;

            // record data to be returned
            poppedData = current->data;

            delete current; // Free node from heap  
            current = NULL; // Point current to NULL for safety
        }

        return poppedData;   
    }
}


// Desc: Return the topmost element of the stack.
// Pre: Stack must not be empty.
// Post: Data of the top node of the stack will be returned.
int Stack::peek() const
{
    if(head == NULL && tail == NULL)
    {
        cout << "ERROR: cant peek at an empty stack, returning 0\n";
        return(0);     
    }
    else
    {
        return(tail->data);        
    }
}

// Desc: Checks if stack is empty or not
// Post: If the stack is empty will return true, else false
bool Stack::isEmpty() const
{
    if(head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Desc: Pretty print for the current stack
// Post: Stack will be printed in a list form, If the stack is empty you will print error message
void Stack::printStack() const 
{
    StackNode *current = head;   // iter for our list

    if(current == NULL)
    {
        cout << "\nStack is empty\n\n";
    }
    else
    {
        cout << endl << " | ";

        // iterate through stack until end
        while(current->next != NULL)
        {       
            cout << current->data << " | ";
            current = current->next;
        }

        cout << current->data << " |\n\n";
    }   
}