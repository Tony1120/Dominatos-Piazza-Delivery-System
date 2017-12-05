#include "restaurant.h"
#include "time.h"
#include "driver.h"

using namespace std;

Restaurant::Restaurant(){
  list<string> drivers;           // empty list of drivers
  list<string> delivered;         // emptry list of delivered pizza     // should it be a string or not?
  queue<string> cooking;          // empty list of food being cooked
  queue<string> delivery;                                               //I dont know what this is . maybe orders waiting to be delivered (departure)?
                            // what else do we need in the constructor??
}

void Restaurant::status(){
  cout << "Orders waiting to cook: " << endl;
  cout <<                     // info for the orders

  cout << "Orders waiting to depart: " << endl;
  cout <<                   // info

  cout << "Drivers: " << endl;
  cout <<                   // info
}

void Restaurant::summary(){
  cout << "Number of orders completed: " << endl;

  cout << "Average time per order: " << endl;

    //use a for loop that goes through the list of drivers
  cout << "Driver" << endl;
  cout << " Number of deliveries completed: " << endl;
  cout << " Average time per delivery: " << endl;
  cout << " Total driving time: " << endl;
  cout << " Total tips: " << endl;
}

Driver * Restaurant::getDriver(string name){
  for(list<int>::iterator it = drivers.begin(); it != drivers.end(); ++it ){
    if(*it = name){
      return *it;
    }
    else{
      return nullptr;
    }
  }
}

void Restaurant::addDriver(Driver* driver){
  drivers.push_back(driver);
}

void Restaurant::addOrder(Order* order){
  cooking.push(order);
}

void Restaurant::serveNextOrder() throw (logic_error){
  if(cooking.empty()){
    throw logic_error("There are no pizza's being cooked ");
  }
  string serve_order = cooking.front();
  cooking.pop();
  delivery.push(serve_order);
}

Order * Restaurant::departNextOrder() throw (logic_error){
  string order_depart = delivery.front();
  return order_depart;
}

void Restaurant::deliver(Driver * driver, Time time, float tip){

}
