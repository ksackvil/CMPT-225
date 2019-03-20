/* 
 * PriorityQueue.cpp
 *
 * Description: 
 *    This class aids the huffman algorithm in which two of the huffman trees with the least frequency
 *    are joined. This class stores each huffman tree in order of the roots frequency (small to large).
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#include <iostream>
#include "PriorityQueue.h"
#include "QNode.h"
#include "HuffmanTree.h"

// Default Constructor
PriorityQueue::PriorityQueue()
{
    head = NULL;
    elementCount = 0;
}

// Destructor
PriorityQueue::~PriorityQueue()
{
    QNode *current = head;

    while (current != NULL)
    {
        // move to next and delete old
        current = current->next;
        delete head;
        head = current;
    }
}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
int PriorityQueue::getElementCount() const
{
    return (elementCount);
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PriorityQueue::isEmpty() const
{
    if (elementCount == 0)
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
bool PriorityQueue::enqueue(const HuffmanTree * newElement)
{
    QNode *newNode = new QNode;

    newNode->data = *newElement;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        QNode *current = NULL;
        QNode *previous = NULL;

        current = head;

        while (current != NULL)
        {
            // Simplest case: new QNode is higher priority, add in before current QNode.
            if (newNode->data.getRootFrequency() < current->data.getRootFrequency())
            {
                // if previous is NULL (no where to add)
                if (elementCount == 1 || current == head)
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
            // Base case: new QNode is lowest priority, add to end of queue.
            else if (current->next == NULL)
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
bool PriorityQueue::dequeue()
{
    if (elementCount != 0)
    {
        QNode *delNode = NULL;

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
HuffmanTree PriorityQueue::peek() const
{
    if(elementCount != 0)
    {
        return head->data;
    }
    else
    {
        cout << "ERROR\n";
        throw "ERROR: Empty data collection";
    }
}

// Description: Overload << opperator. For debugging purposes, outputs
//              each HuffNode object.
// Postcondition: Each HuffNode objects data will be pretty printed.
ostream &operator<<(ostream &os, const PriorityQueue &rhs)
{
    QNode *current = rhs.head;

    os << "elementCount = " << rhs.elementCount << endl
       << endl
       << " | ";

    // // Traverse the list
    while (current != NULL)
    {
        current->data.print();
        os << " | "; // Print data
        current = current->next;                // Go to next QNode
    }

    os << endl;

    return os;
}