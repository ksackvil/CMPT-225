/*
 * test.cpp
 *
 * Description: Driver program for testing our List ADT class.
 *              More specifically, for testing linked list copy and destructor.
 *
 * Creation Date:
 * Author:
 */
#include <iostream>
#include "List.h"

using namespace std;

void listTest();

int main () {

  listTest();
  return 0;
}

void listTest(){
	List ls1;
    
	/* Test Case 1 */
	cout << "Test Case 1: Adding 1,2,3 to the first List object." << endl;
	ls1.add(1);
	ls1.add(2);
	ls1.add(3);
	cout << endl << "Printing the first List object." << endl;
	ls1.printList();
	cout << endl << "Does it contain {1,2,3}?" << endl;

	/* Test Case 2 */
	cout << endl << "Test Case 2: Make a copy of the List object." << endl;
	List ls2(ls1);
	cout << endl << "Print second List object." << endl;
	ls2.printList();
	cout << endl << "Does it contain {1,2,3}?" << endl;

	/* Test Case 3 */
	cout << endl << "Test Case 3: Add 4,5,6 to the first List object." << endl;
	ls1.add(4);
	ls1.add(5);
	ls1.add(6);
	cout << endl << "Print first List object." << endl;
	ls1.printList();
	cout << endl << "Does it contain {1,2,3,4,5,6}?" << endl;
	cout << endl << "Print second List object: (what does it contain?)." << endl;
	ls2.printList();
	cout << endl << "If it was shallow copied, it should contain: {1,2,3,4,5,6}.";
	cout << endl << "If it was deep copied, it should contain: {1,2,3}." << endl;	
	cout << endl;
	
	return; 
}
