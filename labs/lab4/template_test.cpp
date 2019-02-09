#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

int main() {

  List<int> intList;
  cout << endl << endl;

  /* Test Case 1 */
  // An empty 'int' List has already been instantiated - testing the default constructor.
  // Confirm this by printing the List (and testing the method printList() in doing so).
  // We can also confirm the List is empty by calling getElementCount():
  cout << "Test Case 1: Creating an empty List of int's." << endl;
  cout << "Expected Result: The List is empty." << endl; 
  cout << "Actual Result: Is the List empty? elementCount = " << intList.getElementCount() << endl;
  cout << "elements of intList: ";
  intList.printList(); 
  cout << endl << endl;

  /* Test Case 2 */
  cout << "Test Case 2: Testing add() method - Adding the element 3 to the empty List." << endl;
  intList.add(3);
  // Confirm add(3) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
  cout << "Expected Result: The List has one element: 3." << endl;
  cout << "Actual Result: Does the List contain the element 3? elementCount = " << intList.getElementCount() << endl; 	
  cout << "elements of intList: ";
  intList.printList();
  cout << endl << endl;

  cout << "Test Case 3: Testing add() method - Adding 7 to non empty list" << endl;
  intList.add(7);
  // Confirm add(7) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
  cout << "Expected Result: The List has two elements: 7, 3." << endl;
  cout << "Actual Result: Does the List contain the elements? elementCount = " << intList.getElementCount() << endl; 	
  cout << "elements of intList: ";
  intList.printList();
  cout << endl << endl;


  cout << "Test Case 4: Testing add() method - Adding 9 to non empty list" << endl;
  intList.add(5);
  intList.add(6);
  intList.add(9);
  // Confirm add(7) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
  cout << "Expected Result: The List has two elements: 9, 6, 5, 7, 3." << endl;
  cout << "Actual Result: Does the List contain the elements? elementCount = " << intList.getElementCount() << endl; 	
  cout << "elements of intList: ";
  intList.printList();
  cout << endl << endl;

  cout << "Test Case 5: Testing add() method - Adding 9 to non empty list" << endl;
  intList.add(5);
  intList.add(6);
  intList.add(9);
  // Confirm add(7) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
  cout << "Expected Result: The List has two elements: 9, 6, 5, 7, 3." << endl;
  cout << "Actual Result: Does the List contain the elements? elementCount = " << intList.getElementCount() << endl; 	
  cout << "elements of intList: ";
  intList.printList();
  cout << endl << endl;

  return 0;
  
}