#include <iostream>
#include <iomanip>      // std::setw
#include <math.h>       /* log10 */
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

void simulate();
void proccessArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime);
void proccessDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime, int& avgWaitTimeRef);

int main() 
{
    simulate();
    return 0;
}

void simulate()
{
    Queue<Event> bankLine; // Bank line
    PriorityQueue<Event> eventPriorityQueue; // Event Queue

    int inputTime = 0; // first int inputted (time)
    int inputLength = 0; // second int inputted (length)
    int numberOfCustomers = 0; // Total number of customers helped during sim
    int avgWaitTime = 0;
    bool tellerAvailable = true;

    // Create and add arival events to event queue
    while(cin >> inputTime && cin >> inputLength)
    {
        Event newArrivalEvent('A', inputTime, inputLength);
        eventPriorityQueue.enqueue(newArrivalEvent);
    }

    numberOfCustomers = eventPriorityQueue.getElementCount();

    // Event Loop
    cout << "Simulation Begins\n";
    while(!eventPriorityQueue.isEmpty())
    {
        Event newEvent = eventPriorityQueue.peek();
        int currentTime = newEvent.getTime(); // Get current time

        // cout << "event queue: \n" << eventPriorityQueue << endl
        //      <<  "bank line: \n" << bankLine;
        // An arrival event
        if(newEvent.getType() == 'A')
        {
            cout << "Processing an arrival event at time: ";
            cout << setw(4);
            cout << currentTime << endl;
            proccessArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
        }
        else
        {
            cout << "Processing a departure event at time: ";
            cout << setw(3);
            cout << currentTime << endl;
            proccessDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime, avgWaitTime);
        }
    }
    cout << "Simulation Ends\n\n"
        << "Final Statistics:  \n"
        << "	Total number of people processed:  " << numberOfCustomers << endl
        << "	Average amount of time spent waiting: " << ((double) avgWaitTime / (double) numberOfCustomers) << endl;

}

void proccessArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime)
{
    int departureTime = 0;

    // Remove this event from the queue
    eventPriorityQueueRef.dequeue();

    Event customer = arrivalEvent;
    if(bankLineRef.isEmpty() && tellerAvailableRef)
    {
        departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departureTime, 0); 
        eventPriorityQueueRef.enqueue(newDepartureEvent);
        tellerAvailableRef = false;
    }
    else
    {
        bankLineRef.enqueue(customer);
    }
}

void proccessDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime, int& avgWaitTimeRef)
{
    int departureTime = 0;
    
    // Remove this event from the queue
    eventPriorityQueueRef.dequeue();
    if(!bankLineRef.isEmpty())
    {
        // Customer at the front of the line starts transaction
        Event customer = bankLineRef.peek();

        avgWaitTimeRef = avgWaitTimeRef + (currentTime - customer.getTime());

        bankLineRef.dequeue();
        departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departureTime, 0); 
        eventPriorityQueueRef.enqueue(newDepartureEvent);
        tellerAvailableRef = false;
    }
    else
    {
        tellerAvailableRef = true;
    }
}