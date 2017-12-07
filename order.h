//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           order.h
//
//  Declaration for the order class
//
//--------------------------------------------------------------------

#ifndef ORDER_H
#define ORDER_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include "time.h"

class Order{
public:

	//Defaut Constructor
	//Precondition: None
	//Postcondition: creates an order with default values for data members
    Order();

	//Parameterized Constructor
	//Precondition: None
	//Postcondition: creates an order with the given order time and info
	Order(Time time, string info);

    //Pre: Pass time served
    //Post: is_served = true.
    void serve();

	//Precondition: Order is at restaurant
	//Postcondition: Order is out for delivery
    void depart() throw (logic_error);

	//Precondition: Order is out for delivery
	//Postcondition: Order is delivered. Time to delivery is recorded
    void deliver(Time time) throw (logic_error);

	//Precondition: Order is delivered
	//Postcondition: Returns the minutes until the order is delivered (between 'order' and 'deliver' command)
    int getMinToDelivery() throw (logic_error);

	//Precondition: None
	//Postcondition: Returns a string containing the order time and info
    string toString();

private:
    string order_info;
    bool is_out_for_delivery;
    bool is_at_the_restaurant;
    bool is_delivered;
    Time time_placed;
    Time time_delivered;

};

#endif
