#ifndef TIME_H
#define TIME_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;
class Time{
public:
    //Pre: None
    //Post: Creates a time with default values for data members.
    Time();

    //Pre: 0 <= hour <= 23 and 0 <= min <= 59.
    //Post: Creates a time with the given hour and minute.
    Time(int hour, int min) throw (logic_error);

    //Assignment operator
    //Pre: None
    //Assigns other to a Time object
    void operator = ( const Time &other);

    
    //Pre: None
    //Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
    static int elapsedMin(Time t1, Time t2);

    //Pre: Non
    //Post: Returns a string containing the hour and minute (e.g., “13:01”).
    string toString();

private:
  int hour;
  int minutes;
  int curr_time_min;			// Tony requested for this data member
};
#endif
