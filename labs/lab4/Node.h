/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.
#pragma once

template <class ElementType>
class Node
{
public:
	// Public attributes - Why are the attributes public?
	int data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors (why no destructor?)
	Node();
	Node(int theData);
	Node(int theData, Node* theNextNode);

}; // end Node

// ===================== IMPLEMENTATION =================== //

/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */

#include <cstdio>  // Needed for NULL
#include "Node.h"

template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(int theData)
{
	data = theData;
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(int theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

// end Node.cpp