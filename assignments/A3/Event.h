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

#include <iostream>
using namespace std;

class Event 
{
    private:
        char event_type;
        int event_time;
        int event_length;

    public:
        // ===== Constructors ===== //
        Event();
        Event(char startType, int startTime, int startLength);

        // ===== Setters ===== //
        void setType(char newType);
        void setTime(int newTime);
        void setLength(int newLength);

        // ===== Getters ===== //
        char getType() const;
        int getTime() const;
        int getLength() const; 

        // ===== Helpers ===== //
        bool operator<(const Event& e) const;
        friend ostream& operator<<(ostream& os, const Event& e);

};