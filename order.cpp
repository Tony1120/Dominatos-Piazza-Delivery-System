//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           order.cpp
//
//  Implimentation for the time class
//
//--------------------------------------------------------------------
#include "order.h"


//Defaut Constructor
//Precondition: None
//Postcondition: creates an order with default values for data members
Order::Order(){
  //Nothing needs to be done here
}


//Parameterized Constructor
//Precondition: None
//Postcondition: creates an order with the given order time and info
Order::Order(Time placed, string info){
    //Order info
    order_info = info;
    
    //Order is new
    is_out_for_delivery = false;
    is_delivered= false;
    is_at_the_restaurant = true;
    time_placed = placed;
}

//Precondition: Order is at restaurant
//Postcondition: Order is out for delivery
void Order::depart() throw (logic_error){
    if(!is_at_the_restaurant){
        throw logic_error("Order is not at the restaurant");
    }
    is_out_for_delivery = true;
    is_at_the_restaurant = false;
}

//Precondition: Order is out for delivery
//Postcondition: Order is delivered. Time to delivery is recorded
void Order::deliver(Time time)throw (logic_error){
    if(!is_out_for_delivery){
        throw logic_error("Order is not out for delivery");
    }
    
    time_delivered = time;
    is_delivered = true;
}

//Precondition: Order is delivered
//Postcondition: Returns the minutes until the order is delivered (between 'order' and 'deliver' command)
int Order::getMinToDelivery() throw (logic_error){
  if(is_delivered==false)
    throw logic_error("Order has not been delivered");
  return Time::elapsedMin(time_placed, time_delivered);
}


//Precondition: None
//Postcondition: Returns a string containing the order time and info
string Order::toString(){
    string status;
    status = time_placed.toString()+" "+ order_info;
  return status;
}


