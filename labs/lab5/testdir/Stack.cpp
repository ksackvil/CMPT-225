
#include "Stack.h"
#include <iostream>

using namespace std;

// Desc:  Constructor
Stack::Stack() {
    len = 0;
} // constructor



bool Stack::isEmpty() const {
    return len == 0;
} // isEmpty



// Desc:  Insert element x to the top of the stack.
void Stack::push(int x) {
    arr[len++] = x;
} // push



// Desc:  Remove and return element at the top of the stack.
int Stack::pop() {
    return arr[--len];
} // pop



// Desc:  Removes and returns the max element.
//        In case of duplicated max, take the one closest to the top.
//  Pre:  Stack nonempty
// Post:  Order of remaining elements is preserved
int Stack::removeMax() {
    int maxEl = 0;
    int indexOfMaxEl = 0;
    int tempStack[S_CAP]; 
    int count = 0;

    for(int it = 0; it < len; it++) 
    {
        if(it == 0) {
            maxEl = arr[it];
        }
        else if(arr[it] >= maxEl) {
            maxEl = arr[it];
            indexOfMaxEl = it;
        }
    }

    for(int it = 0; it < len; it++) 
    {
        if(it != indexOfMaxEl) {
            tempStack[count] = arr[it];
            count++;
        }
    }

    for(int it = 0; it < count; it++) {
        arr[it] = tempStack[it];
    }

    return maxEl;
} // removeMax


