//--------------------------------------------------------------------
//
//  Final Project                                          pizza.h
//
//  Class declaration for the pizza delivery system
//
//--------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namepace std;

#ifndef PIZZA_H
#define PIZZA_H

      // The Restaurant class keeps track of all drivers and orders in the
      // system, including logged-out drivers and completed orders.
class Restaurant {
public:
  /*
	* Preconditions: None
	* Postcondition: Constructor. Creates a restaurant in an initial state, with
  *                no drivers or orders.
	*/
  Restaurant();

  /*
  * Preconditions: None
  * Postcondition: Prints status of orders and logged-in drivers, as specified
  *                by the “status” command description.
  */
  void status();

  /*
  * Preconditions: None
  * Postcondition: Prints summary statistics on orders and drivers, as specified
  *                by the “summary” command description.
  */
  void summary();

  /*
  * Preconditions: Drive name is passed in as a string
  * Postcondition: If a driver with the given name exists within the system
  *                (logged in or not), returns a pointer to that driver.
  *                Otherwise, returns a null pointer.
  */
  Driver * getDriver(string name);

  /*
  * Preconditions: None
  * Postcondition: Adds the given driver to the system
  */
  void addDriver(Driver* driver);

  /*
  * Preconditions: None
  * Postcondition: Adds the given order to the system, enqueuing it for cooking.
  */
  void addOrder(Order* order);

  /*
  * Preconditions: Cooking queue isnt empty
  * Postcondition: Removes the oldest order from the cooking queue and enqueues
  *                it for departure.
  */
  void serveNextOrder() throw (logic_error);

  /*
  * Preconditions: Departure queue isnt empty
  * Postcondition: Removes the oldest order from the departure queue and returns it.
  */
  Order * departNextOrder() throw (logic_error);

  /*
  * Preconditions: None
  * Postcondition: The order carried by the driver is delivered at the given
  *                time. The driver receives the given tip.
  */
  void deliver(Driver * driver, Time time, float tip);

private:

}

      //The Driver class represents a pizza delivery driver. The driver can be
      //in one of several states: not logged in, logged in and at the restaurant,
      //delivering (i.e., on the way to a delivery), and driving (i.e., on the
      //way back from a delivery). The driver keeps track of its own stats (time
      //delivering, time driving, tips, and number of deliveries). If the driver
      // is currently delivering an order, the driver stores the order.
class Driver {
public:

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  Driver(string name);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  void login() throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  void logout() throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  void depart(Time time, Order o) throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  void deliver(Time time, float tip) throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  void arrive(Time time) throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  string getName();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  bool isLoggedIn();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  int getTotalDeliveries();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  int getTotalMinDelivering();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  int getTotalMinDriving();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  float getTotalTips();

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  Order getOrder() throw(logic_error);

  /*
  * Preconditions: None
  * Postcondition: Constructor. Empty vector of lists created with size set to tableSize
  */
  string toString();

private:

}

class Order{
public:

    //Post: Creates an order with default values for data members.
    Order();

    //Post: Creates an order with the given order time and information.
    Order(Time time, string info);



    //Pre: Order is at the restaurant.
    //Post: Order is out for delivery.
    void depart() throw (logic_error);

    //Pre: Order is out for delivery.
    //Post: Order is delivered. Time to delivery is recorded.
    void deliver(Time time) throw (logic_error);


    //Pre: Order is delivered.
    //Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
    int getMinToDelivery() throw (logic_error);


    //Post: Returns a string containing the order time and info.
    string toString();



private:
};




class Time(){
public:

    //Post: Creates a time with default values for data members.
    Time();

    //Pre: 0 <= hour <= 23 and 0 <= min <= 59.
    //Post: Creates a time with the given hour and minute.
    Time(int hour, int min) throw (logic_error);

    //Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
    static int elapsedMin(Time t1, Time t2);

    //Post: Returns a string containing the hour and minute (e.g., “13:01”).
    string toString();

private:

};
