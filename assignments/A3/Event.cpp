/* 
 * Event.h
 *
 * Description: 
 * 
 * Class Invariant: 
 *
 * Author: Kai Sackville-Hii
 * Date: 
 */

#include "Event.h"

// ===== Constructors ===== //
Event::Event()
{
    event_type = '\0';
    event_time = 0;
    event_length = 0;
}

Event::Event(char startType, int startTime, int startLength)
{
    event_type = startType;
    event_time = startTime;
    event_length = startLength;
}

// ===== Setters ===== //

void Event::setType(char newType)
{
    event_type = newType;
}

void Event::setTime(int newTime)
{
    event_time = newTime;
}

void Event::setLength(int newLength)
{
    event_length = newLength;
}

// ===== Getters ===== //

char Event::getType() const
{
    return(event_type);
}

int Event::getTime() const
{   
    return(event_time);
}

int Event::getLength() const
{
    return(event_length);
}

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

ostream& operator<<(ostream& os, const Event& e)
{
    os << endl 
       << " | " << e.getType() <<  " | " << e.getTime() <<  " | " << e.getLength() << " | "
       << endl;
       
    return os;
}
