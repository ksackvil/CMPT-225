/* 
 * PriorityQueue.h
 *
 * Description: 
 *    This class aids the huffman algorithm in which two of the huffman trees with the least frequency
 *    are joined. This class stores each huffman tree in order of the roots frequency (small to large).
 * 
 * Author: Kai Sackville-Hii
 * Date: March 20, 2019
 */

#pragma once
#include <iostream>
#include "QNode.h"
#include "HuffmanTree.h"

using namespace std;

class PriorityQueue
{
  private:
    QNode *head;       // Pointer to first QNode in the chain
    int elementCount;  // Current count of list items

  public:
    // Default Constructor
    PriorityQueue();

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
    bool enqueue(const HuffmanTree * newElement);

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
    HuffmanTree peek() const;

    // Description: Overload << opperator. For debugging purposes, outputs
    //              each HuffNode object.
    // Postcondition: Each HuffNode objects data will be pretty printed.
    friend ostream &operator<<(ostream &os, const PriorityQueue &rhs);

};