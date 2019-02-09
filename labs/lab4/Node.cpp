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