#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

int main() 
{
    // Event e1, e2('A', 20, 2);   
    PriorityQueue<Event> pq;
    Event e0('A', 1 ,1), e1('A', 2, 4), e2('A', 3, 3), e3('A', 4, 5), e4('A', 5, 5), e5('D', 6, 0), e6('D', 7, 0);

    // e1.setType('A');
    // e1.setTime(21);
    // e1.setLength(2);

    // cout << (e2 < e1) << endl;

    // e1.setType('A');
    // e1.setTime(20);
    // e1.setLength(3);

    // cout << (e2 < e1) << endl;

    // e2.setType('D');
    // e2.setTime(20);
    // e2.setLength(3);

    // cout << (e2 < e1) << endl;
    Queue<Event> q;

    cout << "enqueue 1, 2\n";
    q.enqueue(e0);
    cout << q << endl;
    q.enqueue(e1);
    cout << q << endl;

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

    q.dequeue();
    cout << "dequeue\n"
        << "front is now: "<< q.peek() << endl;
    cout << q << endl;

    cout << "enqueue 6, 7\n";
    q.enqueue(e5);
    cout << q << endl;
    q.enqueue(e6);
    cout << q << endl;


    // q.dequeue();
    // cout << "dequeue\n"
    //     << "front is now: "<< q.peek() << endl;
    // cout << q << endl;
    // q.dequeue();
    // cout << "dequeue\n"
    //     << "front is now: "<< q.peek() << endl;
    // cout << q << endl;
    // q.dequeue();
    // cout << "dequeue\n"
    //     << "front is now: "<< q.peek() << endl;
    // cout << q << endl;
    // q.dequeue();
    // try 
    // {
    // cout << "dequeue\n"
    //     << "front is now: "<< q.peek() << endl;
    // }
    // catch (EmptyDataCollectionException e)
    // {
    //     cout << e.what();
    // }

    // pq.enqueue(e0);
    // cout << "e0" << pq;
    // pq.enqueue(e1);
    // cout << "e1" << pq;
    // pq.enqueue(e2);
    // cout << "e2" << pq;
    // pq.enqueue(e3);
    // cout << "e3" << pq;
    // pq.enqueue(e4);
    // cout << "e4" << pq;
    // pq.enqueue(e5);
    // cout << "e5" << pq;
    // pq.enqueue(e6);
    // cout << "e6" << pq;

    // while(!pq.isEmpty())
    // {
    //     pq.dequeue();
    //     cout << "dequeued" << pq;   
    // }
    return 0;
}