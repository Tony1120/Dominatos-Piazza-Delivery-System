//Defaut Constructor
include "order.h"

Order::Order(){
  //This is a pointless constructor
}

//Parameterized Constructor
Order::Order(Time placed, string info){
  //Order info
  string order_info = info;
  //Order is new
  bool is_out_for_delivery = false;
  bool is_served = false;
  Time time_placed = placed;
  Time time_delivered = NULL;
  //Can time be null?
}

//Depart
void Order::depart() throw (logic_error){
  if(!is_served)
    throw logic_error("Order is uncooked");
  else if(is_out_for_delivery)
    throw logic_error("Order has already left");
  is_out_for_delivery = true;
}

int Order::getMinToDelivery() throw (logic_error){
  if(time_delivered == NULL)
    throw logic_error("Order has not been delivered");
  return Time::elapsedMin(time_placed, time_delivered);
}

//Order status
string Order::toString(){
  stingstream status;
  status << time_placed.toString() << order_info << endl;
  return status.str();
}
