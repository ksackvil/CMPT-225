/*
 * walkIn.cpp
 * 
 * Class Description: Represents the walk-in clinic patient system
 * Class Invariant: 
 *
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#include <iostream>
#include "List.h"
#include "Patient.h"

using namespace std;

int main() 
{
    Patient p1("AAAAAAAAAA"), p2("BBBBBBBBBB"), p3("CCCCCCCCCC"), p4("DDDDDDDDDD"), p5("EEEEEEEEEE");
    List list;

    list.insert(p1);
    list.insert(p2);
    list.insert(p3);
    list.insert(p4);
    list.insert(p5);
    list.printAll();
    cout << endl;

    list.remove(p2);
    list.printAll();
    cout << endl;
    list.remove(p1);
    list.printAll();

    list.removeAll();

    list.insert(p2);
    list.insert(p3);
    list.insert(p4);
    list.printAll();
    
    return(0);
}