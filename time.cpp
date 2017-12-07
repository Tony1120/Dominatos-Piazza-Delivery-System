//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           time.cpp
//
//  Implementation for the time class
//
//--------------------------------------------------------------------

#include "time.h"

using namespace std;

//Default constructor
//Precondition: None
//Postcondition: Creates a time with default values for data members.
Time::Time() {
  hour = 0;
  minutes = 0;
  curr_time_min = (hour * 60) + minutes;
}

//Parameterized constructor
//Precondition: 0 <= hour <= 23 and 0 <= min <= 59.
//Postcondition: Creates a time with the given hour and minute.
Time::Time(int hour, int min) throw (logic_error) {                   
  if(hour<0 || hour>=23){
    throw logic_error("Hour has to be between 0 and 23");
  }
  if(min<0 || min>=60){
    throw logic_error("Minute has to be between 0 and 59");
  }
  this -> hour = hour;
  this -> minutes = min;
  curr_time_min = (hour * 60) + minutes;
}

//Assignment operator
//Precondition: None
//Postcondition: Assigns other to a Time object
void Time::operator = ( const Time &other){
    hour = other.hour;
    minutes = other.minutes;
}

//Precondition: None
//Postcondition: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
int Time::elapsedMin(Time t1, Time t2){
  int min_elasped;
  min_elasped = (t2.hour * 60 + t2.minutes)-(t1.hour * 60 + t1.minutes);
  if(min_elasped < 0) {
    min_elasped = -1 * min_elasped;
  }
  return min_elasped;
}

//Precondition: Non
//Postcondition: Returns a string containing the hour and minute (e.g., “13:01”).
string Time::toString(){
    string the_time;
    string zero_pad = "";
    if(minutes < 10)
        zero_pad = "0"; //This is way cleaner with streams
    string str_hr = to_string(hour);
    string str_min = zero_pad + to_string(minutes);
    the_time = str_hr + ":" + str_min;
    return the_time;
}
