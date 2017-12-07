
#include "order.h"


//Defaut Constructor
Order::Order(){
  //This is a pointless constructor
}


//Parameterized Constructor
Order::Order(Time placed, string info){
    //Order info
    order_info = info;
    
    //Order is new
    is_out_for_delivery = false;
    is_delivered= false;
    is_at_the_restaurant = true;
    time_placed = placed;
}

//Depart
void Order::depart() throw (logic_error){
    if(!is_at_the_restaurant){
        throw logic_error("Order is not at the restaurant");
    }
    is_out_for_delivery = true;
    is_at_the_restaurant = false;
}

//Deliver
void Order::deliver(Time time)throw (logic_error){
    if(!is_out_for_delivery){
        throw logic_error("Order is not out for delivery");
    }
    
    time_delivered = time;
    is_delivered = true;
}

//
int Order::getMinToDelivery() throw (logic_error){
  if(is_delivered==false)
    throw logic_error("Order has not been delivered");
  return Time::elapsedMin(time_placed, time_delivered);
}


//Order status
string Order::toString(){
    string status;
    status = time_placed.toString()+" "+ order_info;
  return status;
}


