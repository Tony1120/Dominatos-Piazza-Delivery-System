//--------------------------------------------------------------------
//
//  Final Project                                          pizza.h
//
//  Class declaration for the pizza delivery system
//
//--------------------------------------------------------------------



#ifndef PIZZA_H
#define PIZZA_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <queue>

using namespace std;
class Time{
public:
    //Pre: None
    //Post: Creates a time with default values for data members.
    Time();

    //Pre: 0 <= hour <= 23 and 0 <= min <= 59.
    //Post: Creates a time with the given hour and minute.
    Time(int hour, int min) throw (logic_error);

    //Pre: None
    //Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
    static int elapsedMin(Time t1, Time t2);

    //Pre: Non
    //Post: Returns a string containing the hour and minute (e.g., “13:01”).
    string toString();
	
    //Pre: Non
    //Post: Returns the current time in minutes. (To be used in drivers class)
    int get_min_time();

private:
  int hour;
  int minutes;
  int curr_time_min;			// Tony requested for this data member
};



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
    bool is_out_for_delivery;
    string order_info;
    bool is_served;            //has it been finished cooking?
    bool has_left_restaurant;
    Time delivered_time;
    
};

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
     * Postcondition: Constructor. Creates a logged-in driver with the given name.
     */
    Driver(string name);
    
    /*
     * Preconditions: Driver is not logged in.
     * Postcondition: Logs the driver in.
     */
    void login() throw(logic_error);
    
    /*
     * Preconditions: Driver is logged in and at the restaurant.
     * Postcondition: Logs the driver out.
     */
    void logout() throw(logic_error);
    
    /*
     * Preconditions: Driver is logged in and at the restaurant.
     * Postcondition: Driver is delivering. Departure time is recorded.
     */
    void depart(Time time, Order o) throw(logic_error);
    
    /*
     * Preconditions: Driver is delivering with a tip >= 0
     * Postcondition: Driver is not delivering. Driver’s stats are updated.
     */
    void deliver(Time time, float tip) throw(logic_error);
    
    /*
     * Preconditions: Driver is driving but not delivering.
     * Postcondition: Driver is at the restaurant. Driver’s stats are updated
     */
    void arrive(Time time) throw(logic_error);
    
    /*
     * Preconditions: None
     * Postcondition: Returns the drivers name
     */
    string getName();
    
    /*
     * Preconditions: None
     * Postcondition: returns true if driver is logged in. Returns false otherwise
     */
    bool isLoggedIn();
    
    /*
     * Preconditions: None
     * Postcondition: Returns the total number of completed deliveries.
     */
    int getTotalDeliveries();
    
    /*
     * Preconditions: None
     * Postcondition: Returns the total minutes spent delivering (i.e., between
     *                “depart” and “deliver” commands).
     */
    int getTotalMinDelivering();
    
    /*
     * Preconditions: None
     * Postcondition: Returns the total minutes spent driving (i.e., between
     *                “depart” and “arrive” commands).
     */
    int getTotalMinDriving();
    
    /*
     * Preconditions: None
     * Postcondition: Returns the total tips received, in dollars
     */
    float getTotalTips();
    
    /*
     * Preconditions: Driver is delivering.
     * Postcondition: Returns the order being delivered.
     */
    Order * getOrder() throw(logic_error);
    
    /*
     * Preconditions: None
     * Postcondition: Returns a string containing the driver’s name, state
     *                (e.g., not logged in), and, if the driver is delivering an
     *                order, the departure time and toString of the order being delivered.
     */
    string toString();
    
private:
    // flags indicating the status of the driver
    bool depart_flag;
    bool deliver_flag;
    bool arrive_flag;
    bool login_flag;
    
    Order currentOrder; // current order of the driver
    string driver_Name; // driver's name
    
    float total_tips;
    int total_deliveries; // total deliveries the driver have
    int tot_mins_spent_driving;
    int tot_mins_spent_delivering;
    
    int depart_time;
    int last_deliver_time;
    int arrive_time;
    
    
};





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
    list<Driver> drivers;
    queue<Order> cooking;
    queue<Order> delivery;
    list<Order> delivered;

};
#endif
 
