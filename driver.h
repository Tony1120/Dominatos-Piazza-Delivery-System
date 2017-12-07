//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           driver.h
//
//  Declaration for the driver class
//
//--------------------------------------------------------------------

#ifndef driver_h
#define driver_h

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include "order.h"
//#include "time.h"

using namespace std;


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
    Order deliver(Time time, float tip) throw(logic_error);
    
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
    bool at_restaurant;
    
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
    
    Time depart_time;
    Time deliver_time;
    Time arrive_time;

};

#endif /* driver_h */
