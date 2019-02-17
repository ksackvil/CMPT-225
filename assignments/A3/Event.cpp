/* 
 * Event.cpp
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

#include "Event.h"

// ---------- CONSTRUCTORS ---------- //

// Default constructor
Event::Event()
{   
    event_type = '\0';
    event_time = 0;
    event_length = 0;
}

// Parameterized constructor
Event::Event(char startType, int startTime, int startLength)
{
    event_type = startType;
    event_time = startTime;
    event_length = startLength;
}

// ---------- SETTERS ---------- //

// Description: Sets the current event_type to a new char.
// Postcondition: event_type is set to newType.
void Event::setType(char newType)
{
    event_type = newType;
}

// Description: Sets the current event_time to a new int.
// Postcondition: event_time is set to newTime.
void Event::setTime(int newTime)
{
    event_time = newTime;
}


// Description: Sets the current event_length to a new int.
// Postcondition: event_length is set to newLength.
void Event::setLength(int newLength)
{
    event_length = newLength;
}

// ---------- GETTERS ---------- //

// Description: Gets the current event_type.
// Postcondition: event_type is returned.
char Event::getType() const
{
    return(event_type);
}

// Description: Gets the current event_time.
// Postcondition: event_time is returned.
int Event::getTime() const
{   
    return(event_time);
}

// Description: Gets the current event_length.
// Postcondition: event_length is returned.
int Event::getLength() const
{
    return(event_length);
}

// ---------- HELPERS ---------- //

// Description: Overload < opperator. Helps to evaluate two Event objects
//              in terms of priority, where the object E1 is higher priority than
//              E2 if E1 < E2.
// Precondition: event_type of both objects must be == 'A' or 'D'.
// Postcondition: will return true(1) if the current object is less than the refranced
//                else returns false(0).
bool Event::operator<(const Event& e) const
{
    bool return_value = false;

    // if the events times are equal must check length 
    if(event_time == e.event_time)
    {
        if(event_type != e.event_type)
        {
            return_value = (event_type == 'A' && e.event_type == 'D');
        }
        else
        {
            if(event_type == 'A')
            {
                return_value = (event_length > e.event_length);
            }
            else
            {
                return_value = false;
            }    
        }   
    }
    else
    {
        return_value = (event_time < e.event_time);
    }

    return return_value;
}

// Description: Overload << opperator. For debugging purposes, outputs 
//              Event objects event_type, event_time, and event_length.
// Postcondition: Event objects data will be pretty printed
ostream& operator<<(ostream& os, const Event& e)
{
    os << endl 
       << " | " << e.getType() <<  " | " << e.getTime() <<  " | " << e.getLength() << " | "
       << endl;
       
    return os;
}
