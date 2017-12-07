//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           time.h
//
//  Declaration for the time class
//
//--------------------------------------------------------------------

#ifndef TIME_H
#define TIME_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;
class Time{
public:

	//Default constructor
    //Precondition: None
    //Postcondition: Creates a time with default values for data members.
    Time();

	//Parameterized constructor 
    //Precondition: 0 <= hour <= 23 and 0 <= min <= 59.
    //Postcondition: Creates a time with the given hour and minute.
    Time(int hour, int min) throw (logic_error);

    //Assignment operator
    //Precondition: None
    //Postcondition: Assigns other to a Time object
    void operator = ( const Time &other);

    
    //Precondition: None
    //Postcondition: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
    static int elapsedMin(Time t1, Time t2);

    //Precondition: Non
    //Postcondition: Returns a string containing the hour and minute (e.g., “13:01”).
    string toString();

private:
  int hour;
  int minutes;
  int curr_time_min;			// current time in minutes
};
#endif
