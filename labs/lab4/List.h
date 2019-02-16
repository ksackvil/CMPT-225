/*
 * List.h - Header of the List class
 *
 * Class Description: Unsorted List data collection ADT class. 
 *
 * Creation Date: 
 * Author: 
 */
 
 /* NOTE: This is a link-based implementation of a List ADT class.
 *        Its underlying data structure is a singly-headed singly-linked list (SHSL).   
 */

// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.
#pragma once
#include "Node.h"

template <class ElementType>
class List
{

private:
  ElementType elementCount;  // Number of elements currently stored in the List.
	Node<ElementType> *head;        // Pointer to the first node in the List.

public:
	// Constructors and Destructors

	/* Generally, every class that makes use of dynamically allocated memory
	 * should have at least two constructors:
	 *   - a default constructor and 
	 *   - a copy constructor that creates a distinct copy of the given object
	 * (even if the client code does not make use of all of these constructors).
	 */

	// Description: Default constructor
	List(); 
	
		
	/* Note that the compiler will generate a copy constructor automatically.  
	 * However, this constructor only creates a SHALLOW COPY (so would only copy the
	 * elementCount and head variables). In this case, this would NOT CREATE A
	 * NEW LIST object, just a new reference to "this" List object.  
	 * It is therefore necessary to write a constructor that makes a DEEP COPY
	 * if our class makes use of dynamically allocated memory.
	 */

	/* Also note the parameter. C++ functions use pass-by-value by
	 * default. This means that the functions make copies of the given
	 * arguments. This is inefficient (particularly for large objects).
	 * Therefore it is normal to pass a reference, (using &) of the parameter,
	 * called an "alias".
	 * Furthermore, if the parameter cannot be changed, it is good programming practice 
	 * to indicate so by using the keyword "const". This keyword prevents it from being changed,
	 * i.e., the compiler will complaint if the code tries to change the value of the parameter.
	 */
 
	// Description: Copy constructor to copy an existing List object. 
	List(const List& lst);
	 
	
	/* The destructor is responsible for deleting any memory that was dynamically
	 * allocated by an object. If there is no such memory, no destructor needs to
	 * be created (the compiler automatically creates one). 
	 * Because this class makes use of dynamically allocated memory
	 * i.e., uses pointers when new Node objects are instantiated, it is necessary to write 
	 * a destructor. Destructors are identified by the "~" preceding the class name.
	 * There can be only one destructor for a class, and it cannot have parameters. 
	 */
	// Description: Destructor.
	~List();


	/**************************************************************************/
	// List Public Interface 
	
	// Description: Returns the number of elements in the List.
	int getElementCount() const;

    // Description: Adds an element "newElement" at the front of the List.
	//              Returns true if "newElement" has been added to the List, false otherwise.
	bool add(ElementType newElement);
	
	// Description: Removes The first instance of "toBeRemoved" from the List.
	//              Returns true if "toBeRemoved" is found and removed, false otherwise.
	// PreCondition: List is not empty.
	bool remove(ElementType toBeRemoved);
	
	// Description: Empties the List, freeing up dynamically allocated memory.
	// PreCondition: List is not empty.
	void removeAll();

	// Description: Prints the contents of the List from the first to the last element.
	/* 
	 * Note that there is some debate about whether or not this type of
	 * method belongs in a class. The argument (briefly) is that a class
	 * shouldn't be responsible for I/O by "displaying" itself as it cannot 
	 * foresee how it is to be displayed (in a TUI or GUI environment?).
	 * However, such method eases testing.
	 * For testing purpose, unless required by client in problem statement.
	 * Could also overload operator<<. 
	 */
	void printList();

}; // end of header file of List class

// ===================== IMPLEMENTATION =================== //
/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: Unsorted List data collection ADT class. 
 *
 * Creation Date: 
 * Author: 
 */
 
 /* NOTE: This is a link-based implementation of a List ADT class.
 *        Its underlying data structure is a singly-headed singly-linked list (SHSL).   
 */ 


#include <string>
#include <iostream>
#include "List.h"


using namespace std; // Needed for cout, cin to be recognized

// Constructors and Destructors

/* Generally, every class that makes use of dynamically allocated memory
 * should have at least two constructors:
 *   - a default constructor and 
 *   - a copy constructor that creates a distinct copy of the given object
 * (even if the client code does not make use of all of these constructors).
 */

// Description: Default constructor
template <class ElementType>
List<ElementType>::List(){
	elementCount = 0;
	head = NULL;
	
	cout << "List Default constructor" << endl; // For learning purposes!
}


/* Note that the compiler will generate a copy constructor automatically.  
 * However, this constructor only creates a SHALLOW COPY (so would only copy the
 * elementCount and head variables). In this case, this would NOT CREATE A
 * NEW LIST object, just a new reference to "this" List object.  
 * It is therefore necessary to write a constructor that makes a DEEP COPY
 * if our class makes use of dynamically allocated memory.
 */

/* Also note the parameter. C++ functions use pass-by-value by
 * default. This means that the functions make copies of the given
 * arguments. This is inefficient (particularly for large objects).
 * Therefore it is normal to pass a reference, (using &) of the parameter,
 * called an "alias".
 * Furthermore, if the parameter cannot be changed, it is good programming practice 
 * to indicate so by using the keyword "const". This keyword prevents it from being changed,
 * i.e., the compiler will complaint if the code tries to change the value of the parameter.
 */
 
// Description: Copy constructor to copy an existing List object. 
template <class ElementType>
List<ElementType>::List(const List& lst){	if (lst.head == NULL){
		head = NULL;
		elementCount = 0;
	}
	else{
		// Copy first node and assign head
		/* OK, what's with the "->"?  The "->" operator accesses the attribute
		 * or method of the object (or struct) that is refererred to by a
		 * pointer.  So "head -> data" is the contents of the data variable
		 * of the object that head points to.  Note that this is synonomous
		 * with "(*head).data" but the latter syntax is ugly and confusing and
		 * is therefore rarely used. */
		head = new Node<ElementType>;
		head->data = lst.head->data;
		/* Now copy the rest of the list.  To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */
		Node<ElementType> *pNewNode = head;
		Node<ElementType> *pOldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (pOldNode != NULL){
			pNewNode->next = new Node<ElementType>;
			pNewNode = pNewNode->next;
			pNewNode->data = pOldNode->data;
			pOldNode = pOldNode->next;
		}
		pNewNode->next = NULL;
		elementCount = lst.elementCount;
	}
	
	cout << "List Copy constructor" << endl; // For learning purposes!
}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object. If there is no such memory, no destructor needs to
 * be created (the compiler automatically creates one). 
 * Because this class makes use of dynamically allocated memory
 * i.e., uses pointers when new Node objects are instantiated, it is necessary to write 
 * a destructor. Destructors are identified by the "~" preceding the class name.
 * There can be only one destructor for a class, and it cannot have parameters. 
 */
// Description: Destructor.
template <class ElementType>
List<ElementType>::~List(){
	removeAll();
	cout << "List destructor" << endl; // For learning purposes!
}


/**************************************************************************/
// List Public Interface 

// Description: Returns the number of elements in the List.
template <class ElementType>
int List<ElementType>::getElementCount() const {
	return elementCount;
}

// Description: Adds an element "newElement" at the front of the List.
//              Returns true if "newElement" has been added to the List, false otherwise.
template <class ElementType>
bool List<ElementType>::add(ElementType newElement){
	Node<ElementType> *p = new Node<ElementType>; //temporary node
	bool result = false;
	
	if ( p != NULL ) { 
		// Assign appropriate values to the new node
		p->data = newElement;
		p->next = head;
		// Make the head point to the new node
		head = p;	
		elementCount++;
		result = true;
	}
	return result;
}

// Description: Removes The first instance of "toBeRemoved" from the List.
//              Returns true if "toBeRemoved" is found and removed, false otherwise.
// PreCondition: List is not empty.
template <class ElementType>
bool List<ElementType>::remove(ElementType toBeRemoved) {
	Node<ElementType> *p = head;
	Node<ElementType> *temp;
	bool result = false;
	
	// Is the List empty?
	if (head == NULL) {
		result = false;
	}
	else { // Check to see if toBeRemoved is at the head of the list
	    if (head->data == toBeRemoved){
			head = head->next;
			delete p; //currently assigned head
			elementCount--;
			result = true;
	    }
	    else  { // Otherwise iterate through list
			for ( int i = 0; i < elementCount-1; i++ ) {
				// Check next node for toBeRemoved
				if (p->next->data == toBeRemoved){
					temp = p->next;
					p->next = p->next->next;
					elementCount--;
					delete temp;
					result = true;
				}
				p = p->next;
			}
		}
	}
	return result;
}

// Description: Empties the List, freeing up dynamically allocated memory.
// PreCondition: List is not empty.
template <class ElementType>
void List<ElementType>::removeAll(){
	Node<ElementType> *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL){
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	head = NULL;
	elementCount = 0;
}

// Description: Prints the contents of the List from the first to the last element.
/* 
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot 
 * foresee how it is to be displayed (in a TUI or GUI environment?).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<. 
 */
template <class ElementType>
void List<ElementType>::printList(){
	Node<ElementType> *p = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << p->data; // Print data
		p = p -> next; // Go to next Node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be wanted
}
// end of implementation file of List class