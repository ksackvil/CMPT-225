/*
 * Node.h
 *
 * Description: Node of a singly linked list 
 *              in which the data is of "int" data type.
 *              Designed and implemented as a non-ADT.
 *
 * Author: Kai Sackville-Hii
 * Date: February 27, 2019
 */
 
#pragma once
#include <cstdio>  // Needed for NULL

/******* Node Public Interface - START - *******/
template <class ElementType>
class Node
{
public:
	ElementType data;   // The data in the node
	Node* next;   		// Pointer to next node
	
	// default constructor
	Node();

	// one parameter constructor
	Node(ElementType theData);

	// two parameter constructor
	Node(ElementType theData, Node* theNextNode);

};
/******* Node Public Interface - END - *******/

/******* Node Implementation - START - *******/
// default constructor
template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

// one parameter constructor
template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

// two parameter constructor
template <class ElementType>
Node<ElementType>::Node(ElementType theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}
/******* Node Implementation - END - *******/