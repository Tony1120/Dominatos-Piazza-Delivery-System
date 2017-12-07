//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           restaurant.cpp
//
//  Implementation for the restaurant class
//
//--------------------------------------------------------------------

#include "restaurant.h"

using namespace std;

/*
* Preconditions: None
* Postcondition: Constructor. Creates a restaurant in an initial state, with
*                no drivers or orders.
*/
Restaurant::Restaurant(){
  list<Driver> drivers;           // empty list of drivers
  list<Order> delivered;         // emptry list of delivered pizza
  deque<Order> toCook;           // empty deque of food waiting to be cooked
  deque<Order> served;          // empty deque of orders served
}

/*
* Preconditions: None
* Postcondition: Prints status of orders and logged-in drivers, as specified
*                by the “status” command description.
*/
void Restaurant::status(){
	//for orders waiting to cook
  cout << "Orders waiting to cook: " << endl;
  for( auto &cookItr : toCook){
    cout << '\t' << cookItr.toString() << endl;
  }
  //for orders waiting to depart
  cout << "Orders waiting to depart: " << endl;
  for( auto &serveItr : served){
    cout << '\t' << serveItr.toString() << endl;
  }
  //for driver details 
  cout << "Drivers: " << endl;
  for( auto &driverItr : drivers){
    cout << '\t' << driverItr.toString() << endl;
  }
        cout<<endl;
}

/*
* Preconditions: None
* Postcondition: Prints summary statistics on orders and drivers, as specified
*                by the “summary” command description.
*/
void Restaurant::summary(){
	//for number of orders completed
  cout << "Number of orders completed: ";
  //Number delivered
  int completed = 0;
  int totalTime = 0;
  for(auto &orderItr : delivered){
    completed++; 
    totalTime += orderItr.getMinToDelivery();
  }
  cout << completed << endl;

    float average_time_per_order;
    
    if (completed==0) {
        average_time_per_order=0.00;
    }
    else{
        average_time_per_order=(float)totalTime/completed;
    }
	//for average time per order
  cout << "Average time per order: ";
  cout << average_time_per_order << endl;
    cout << endl;

    //For loop that goes through the list of drivers
  for(auto &driver : drivers){
    cout << "Driver " << driver.getName() << endl;
    cout << "\tNumber of deliveries completed: " << driver.getTotalDeliveries() << endl;
      
      int totalmindelivering = driver.getTotalMinDelivering();
      int totaldeliveries = driver.getTotalDeliveries();
      float average_time_per_delivery;
      if (totaldeliveries==0) {
          average_time_per_delivery=0;
      }
      else{
          average_time_per_delivery= totalmindelivering/ totaldeliveries;
      }
    cout << "\tAverage time per delivery: " <<average_time_per_delivery << endl;
      
    cout << "\tTotal driving time: " << driver.getTotalMinDriving() << endl;
    cout << "\tTotal tips: " << driver.getTotalTips() << endl;
    
      cout<<endl;
  }
}

/*
* Preconditions: Drive name is passed in as a string
* Postcondition: If a driver with the given name exists within the system
*                (logged in or not), returns a pointer to that driver.
*                Otherwise, returns a null pointer.
*/
Driver * Restaurant::getDriver(string name){
  for(list<Driver>::iterator it = drivers.begin(); it != drivers.end(); ++it ){
    if(it->getName() == name){
      return &*it;
    }
  }
  return nullptr;
}

/*
* Preconditions: None
* Postcondition: Adds the given driver to the system
*/
void Restaurant:: addDriver(string name){
    drivers.push_back(Driver(name));
}
    

/*
* Preconditions: None
* Postcondition: Adds the given order to the system, enqueuing it for cooking.
*/
void Restaurant::addOrder( Order & order){
    toCook.push_back(order);
}

/*
* Preconditions: Cooking queue isnt empty
* Postcondition: Removes the oldest order from the cooking queue and enqueues
*                it for departure.
*/
void Restaurant::serveNextOrder() throw (logic_error){
  if(toCook.empty()){
    throw logic_error("There are no pizzas being cooked ");
  }
    
    Order serve_order= toCook.front();
    toCook.pop_front();
    served.push_back(serve_order);
}

/*
* Preconditions: Departure queue isnt empty
* Postcondition: Removes the oldest order from the departure queue and returns it.
*/
Order Restaurant::departNextOrder() throw (logic_error){
    if (served.empty()) {
        throw logic_error("There are no pizzas ready to be delivered ");
    }
    
    Order order_depart = served.front();
    served.pop_front();
    
    return order_depart;
}

/*
* Preconditions: None
* Postcondition: The order carried by the driver is delivered at the given
*                time. The driver receives the given tip.
*/
void Restaurant::deliver(Driver & driver, Time time, float tip){
    delivered.push_back(driver.deliver(time, tip));
}
