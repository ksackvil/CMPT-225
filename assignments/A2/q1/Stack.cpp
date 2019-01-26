/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
 
#include <cstddef>  // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    head = NULL;
    tail = NULL;
}

Stack::~Stack() 
{   
    StackNode *current = head;

    while(current != NULL)
    {
        current = current->next;
        delete head;
        head = current;
    }
}

void Stack::push(int x) 
{
    StackNode *newNode = new StackNode; 

    newNode->data = x;
    newNode->next = NULL;   

    if(head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int Stack::pop()
{
    StackNode *current = head;
    StackNode *previous = head;
    int poppedData = 0;

    if(head == tail)
    {
        poppedData = tail->data;
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        while(current->next != NULL)
        {       
            previous = current;
            current = current->next;
        }

        tail = previous;
        tail->next = NULL;

        poppedData = current->data;

        delete current;   
    }

    return poppedData;   
}

int Stack::peek() const
{
    return(tail->data);
}

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



