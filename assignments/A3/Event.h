/* 
 * Event.h
 *
 * Description: 
 *     This class models the customer being served and the events which will occur 
 *     during the bank simulation. Each event has the following data members: event_type(char) -
 *     defines which type of event (A = arrival, D = departure), event_time(int) - is the time 
 *     at which the event occurs, and event_length(int) - is the length for which the event lasts.
 *
 * Class Invariant: 
 *     The class member event_type must be a char with only one of the two values - A or D.
 * 
 * Author: Kai Sackville-Hii
 * Date: February 27, 2019
 */

#pragma once
#include <iostream>
using namespace std;

class Event 
{
    private:
        char event_type;    // either 'A' or 'D'
        int event_time;
        int event_length;

    public:

        // ---------- CONSTRUCTORS ---------- //

        // Default constructor
        Event();

        // Parameterized constructor
        Event(char startType, int startTime, int startLength);

        // ---------- SETTERS ---------- //

        // Description: Sets the current event_type to a new char.
        // Postcondition: event_type is set to newType.
        void setType(char newType);
        
        // Description: Sets the current event_time to a new int.
        // Postcondition: event_time is set to newTime.
        void setTime(int newTime);

        // Description: Sets the current event_length to a new int.
        // Postcondition: event_length is set to newLength.
        void setLength(int newLength);

        // ---------- GETTERS ---------- //

        // Description: Gets the current event_type.
        // Postcondition: event_type is returned.
        char getType() const;
        
        // Description: Gets the current event_time.
        // Postcondition: event_time is returned.
        int getTime() const;

        // Description: Gets the current event_length.
        // Postcondition: event_length is returned.
        int getLength() const; 

        // ---------- HELPERS ---------- //

        // Description: Overload < opperator. Helps to evaluate two Event objects
        //              in terms of priority, where the object E1 is higher priority than
        //              E2 if E1 < E2.
        // Precondition: event_type of both objects must be == 'A' or 'D'.
        // Postcondition: will return true(1) if the current object is less than the refranced
        //                else returns false(0).
        bool operator<(const Event& e) const;

        // Description: Overload << opperator. For debugging purposes, outputs 
        //              Event objects event_type, event_time, and event_length.
        // Postcondition: Event objects data will be pretty printed
        friend ostream& operator<<(ostream& os, const Event& e);

};