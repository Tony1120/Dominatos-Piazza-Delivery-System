

#ifndef ORDER_H
#define ORDER_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include "time.h"

class Order{
public:

    //Post: Creates an order with default values for data members.
    Order();

    //Post: Creates an order with the given order time and information.
    Order(Time time, string info);

    //Pre: Pass time served
    //Post: is_served = true.
    void serve();

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
    string order_info;
    bool is_out_for_delivery;
    bool is_at_the_restaurant;
    bool is_delivered;
    //Time time_served;
    Time time_placed;
    Time time_delivered;

};

#endif
