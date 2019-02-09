
#include <iostream>
#include "Stack.h"


using namespace std;

int main () {
    Stack SA, SB;
    int resA, resB;

    int A[10] = { 13, 8, 2, 3, 1, 5, 21, 1, 55, 34};
    int B[10] = { 25, 64, 100, 81, 49, 1, 9, 16, 4, 36};

    for (int i = 0; i < 10; i++) {
        SA.push(A[i]);
        SB.push(B[i]);
    } // for

    resA = SA.removeMax();
    resB = SB.removeMax();

    if (resA == 55 && resB == 100) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail:  resA=" << resA << " resB=" << resB << endl;
    }

    return 0;
} // main

