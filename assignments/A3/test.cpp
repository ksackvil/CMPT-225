#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

int main() 
{
    // Event e1, e2('A', 20, 2);   
    // PriorityQueue<Event> pq;

    // ----- TESTING EVENT CLASS ----- //
    cout << "\n\n ---------- TESTING EVENT CLASS: START --------- \n\n";
    // constructors and parameterized constructor
    Event e0, e1('A', 22, 4), e2('A', 20, 6), e3('A', 23, 2), e4('A', 30, 3);
    
    // setType, setTime and setLength
    e0.setType('A');
    e0.setTime(1);
    e0.setLength(5);

    cout << "e0 < e1\n" << "expected result : 1\n" << "actual result: ";

    // opperator <
    cout << (e0 < e1) << endl;

    e0.setTime(22);
    cout << "Changing time to 22\n" << e0 << endl;

    cout << "e0 < e1\n" << "expected result : 1\n" << "actual result: ";
    cout << (e0 < e1) << endl;

    // opperator <<
    e0.setType('D');
    cout << "Changing type to 'D'\n" << e0 << endl;

    cout << "e0 < e1\n" << "expected result : 0\n" << "actual result: ";
    cout << (e0 < e1) << endl;

    cout << "Geting data... should be D 22 5\n";
    // getType, getTime, and getLength
    cout << e0.getType() << " " << e0.getTime() << " " << e0.getLength() << endl;
    cout << "\n\n ---------- TESTING EVENT CLASS: END --------- \n\n";

    // ----- TESTING QUEUE CLASS ----- //
    cout << "\n\n ---------- TESTING QUEUE CLASS: START --------- \n\n";
    Queue<Event> q;

    // isEmpty
    cout << "empty queue test isEmpty()\n" << "expected: 1\n"
        << "actual: " << q.isEmpty() << endl; 

    // enqueue and opperator << 
    cout << "enqueue 1, 2\n";
    q.enqueue(e1);
    cout << q << endl;
    q.enqueue(e2);
    cout << q << endl;

    // dequeue and peek
    q.dequeue();
    cout << "dequeue\n"
        << "front is now: "<< q.peek() << endl;
    cout << q << endl;

    cout << "enqueue 3, 4, 5\n";
    q.enqueue(e2);
    cout << q << endl;
    q.enqueue(e3);
    cout << q << endl;
    q.enqueue(e4);
    cout << q << endl;
    cout << "\n\n ---------- TESTING QUEUE CLASS: END --------- \n\n";

    cout << "\n\n ---------- TESTING PRIORITYQUEUE AND NODE CLASS: START --------- \n\n";
    // default constrctor
    PriorityQueue<Event> pq;

    // enqueue
    cout << "e0" << pq;
    pq.enqueue(e0);
    cout << "e1" << pq;
    pq.enqueue(e1);
    cout << "e2" << pq;
    pq.enqueue(e2);
    cout << "e3" << pq;
    pq.enqueue(e3);
    cout << "e4" << pq;
    pq.enqueue(e4);

    // opperator << 
    cout << "\nQueue looks like ... should be in order\n" << pq << endl;
    cout << "\n\n ---------- TESTING PRIORITYQUEUE AND NODE CLASS: END --------- \n\n";

    // copy constructor
    PriorityQueue<Event> testCopyConstructor(pq);
  
    cout << "\ntesting copy constructor, should be identical to queue above...\n";
    cout << testCopyConstructor << endl;

    // dequeue
    while(!pq.isEmpty())
    {
        pq.dequeue();
        cout << "dequeued" << pq;   
    }

    return 0;
}