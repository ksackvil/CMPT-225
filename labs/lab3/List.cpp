/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: A data collection List ADT class.
 *
 * Creation Date:
 * Author:
 */

#include "List.h"
#include "Node.h"
#include <string>
#include <iostream>

using namespace std; // Needed for cout, cin to be recognized

// Constructors and Destructors

/* Generally, if a class makes use of dynamic memory allocation,
 * we should provide at least two constructors: a default constructor and
 * a copy constructor that creates a deep copy of the given object.
 */

// Description: Default constructor
List::List(){
	elementCount = 0;
	head = NULL;
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
 * Therefore it is normal to pass a reference, (using &) to the parameter.
 * Also, if the parameter must not be changed,
 * it is good practice to make it const, which prevents it from being changed.
 */
// Description: Copy constructor to copy an existing List object.
List::List(const List& lst)
{
	// copy element count
	elementCount = lst.elementCount;

	// make sure head isnt null
	if(lst.head != NULL)
	{
		// create temp iter point to new node and point temp head to that
		Node *tempCurrent = new Node;	
		Node *tempHead = tempCurrent;

		// point current to head
		Node *current = lst.head;

		// copy data 
		tempCurrent->data = current->data;

		// move to next current node 
		current = current->next;
		
		while(current != NULL)
		{
			// add node and move to it
			tempCurrent->next = new Node;
			tempCurrent = tempCurrent->next;
			
			// copy over data
			tempCurrent->data = current->data;
			
			// move to next node
			current = current->next;
		}	

		// head now points to temp head aka our copied ll
		head = tempHead;
	}

}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object. If there is no such memory, no destructor needs to
 * be created (the compiler automatically creates one). Because this class
 * uses memory dynamically allocated (and pointers) when new Node objects are
 * instantiated, it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name.
 * There can be only one destructor for a class, and it cannot have parameters.
 */
List::~List(){
    Node *current = head;

    while(current != NULL)
    {
        current = current->next;
        delete head;
        head = current;
    }
}

/**************************************************************************/
// List Operations
//
// Description: Add an element (newElement) to the list.
// Postcondition: A new node containing the given element is inserted at the end of the list.
// Parameter: newElement is the element to be stored.
void List::add(int newElement){
	Node *newNode = new Node(newElement); //new Node with x

	// Check to see if list is empty
	if (head == NULL){
		// Make new Node the new head
		head = newNode;
	}else{
		// Move to the end of the list
		Node* current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	elementCount++;
}


// Description: Prints the contents of the list from the first to the last element.
/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
void List::printList(){
	Node *current = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != NULL){
		cout << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be wanted
}
// end of implementation file of List class
