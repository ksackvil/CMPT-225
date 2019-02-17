/*
 * SimApp.cpp
 *
 * Description: Computer modal to simulate a bank queue, implemented using a priority queue. 
 *              This program will simulate the time it takes to wait in line at a bank, 
 *              an approximate average wait time will be calculated and returned.
 *
 * Author: Kai Sackville-Hii
 * Date: February 27, 2019
 */

#include <iostream>
#include <iomanip>      // std::setw
#include <math.h>       /* log10 */
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

// ---------- FUNCTION DEFFINITIONS START ---------- //
// Description: Main loop for simulation, reads from cin for all events than runs simulation
//              to calculate average wait times.
// Postcondition: The average wait time calculated from the given inputs will be printed.
void simulate();

// Description: Handles an arrival event.
// Postcondition: Highest priority event in eventPriorityQueueRef will be dequeued, bankLineRef and
//                tellerAvailableRef will be updated.
void proccessArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime);

// Description: Handles a departure event.
// Postcondition: Highest priority event in eventPriorityQueueRef will be dequeued, bankLineRef and
//                tellerAvailableRef will be updated. The average wait time will be recalculated and updated.
void proccessDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime, int& avgWaitTimeRef);
// ---------- FUNCTION DEFFINITIONS END ---------- //

// ---------- DRIVER START ---------- //
int main() 
{
    simulate();
    return 0;
}
// ---------- DRIVER END ---------- //

// ---------- SIMULATION FUNCTIONS START ---------- //
// Description: Main loop for simulation, reads from cin for all events than runs simulation
//              to calculate average wait times.
// Postcondition: The average wait time calculated from the given inputs will be printed.
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

// Description: Handles an arrival event.
// Postcondition: Highest priority event in eventPriorityQueueRef will be dequeued, bankLineRef and
//                tellerAvailableRef will be updated.
void proccessArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime)
{
    int departureTime = 0;

    // Remove this event from the queue
    eventPriorityQueueRef.dequeue();

    Event customer = arrivalEvent;
    if(bankLineRef.isEmpty() && tellerAvailableRef)
    {
        // create new departure event for customer arriving
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

// Description: Handles a departure event.
// Postcondition: Highest priority event in eventPriorityQueueRef will be dequeued, bankLineRef and
//                tellerAvailableRef will be updated. The average wait time will be recalculated and updated.
void proccessDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueueRef, Queue<Event>& bankLineRef, bool& tellerAvailableRef, const int currentTime, int& avgWaitTimeRef)
{
    int departureTime = 0;
    
    // Remove this event from the queue
    eventPriorityQueueRef.dequeue();

    if(!bankLineRef.isEmpty())
    {
        // Customer at the front of the line starts transaction
        Event customer = bankLineRef.peek();
        bankLineRef.dequeue();

        // update the average wait time based on new departure event
        avgWaitTimeRef = avgWaitTimeRef + (currentTime - customer.getTime());

        // create new departure event for next customer in bank line
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
// ---------- SIMULATION FUNCTIONS END ---------- //
