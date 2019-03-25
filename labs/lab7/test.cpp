#include <iostream>
#include "BinaryHeap.h"
#include "Event.h"

using namespace std;

int main() 
{
    BinaryHeap b;
    Event e1('A', 2, 5), e2('A', 4, 5), e3('A', 6, 5), e4('A', 8, 5);

    b.insert(e4);
    b.insert(e3);
    b.insert(e2);
    b.insert(e1);

    cout << "retriveing top\n";
    cout << b.retrieve();
    cout << b;
    b.remove();
    cout << "retriveing top\n";
    cout << b.retrieve();
    cout << b;
    cout << b.getElementCount() << endl;
    return 0;
}