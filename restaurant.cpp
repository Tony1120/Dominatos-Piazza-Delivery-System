#include "restaurant.h"
#include "time.h"
#include "driver.h"
#include "order.h"

using namespace std;

Restaurant::Restaurant(){
  list<driver> drivers;           // empty list of drivers
  list<order> delivered;         // emptry list of delivered pizza   
  queue<order> toCook;          // empty list of food waiting to be cooked
  queue<order> served;        //orders waiting to be delivered (departure)?
                            // what else do we need in the constructor??
}

void Restaurant::status(){
  cout << "Orders waiting to cook: " << endl;
  for(auto &cookItr : toCook){
    cout << '\t' << cookItr.toString() << endl;
  }

  cout << "Orders waiting to depart: " << endl;
  for(auto &serveItr : served){
    cout << '\t' << serveItr.toString() << endl;
  }

  cout << "Drivers: " << endl;
  for(auto &driverItr : drivers){
    cout << '\t' << driverItr.toString() << endl;
  }
}

void Restaurant::summary(){
  cout << "Number of orders completed: ";
  //Number delivered
  int completed = 0;
  int totalTime = 0;
  for(auto &orderItr : delivered){
    completed++; 
    totalTime += orderItr.getMinToDelivery();
  }
  cout << completed << endl;

  cout << "Average time per order: ";
  cout << (float)totalTime/completed << endl;

    //use a for loop that goes through the list of drivers
  for(auto &driver : drivers){
    cout << "Driver " << driver.getName() << endl;
    cout << "\tNumber of deliveries completed: " << driver.getTotalDeliveries() << endl;
    cout << "\tAverage time per delivery: " << (float)(driver.getTotalMinDelivering()/driver.getTotalDeliveries()) << endl;
    cout << "\tTotal driving time: " << driver.getTotalMinDriving() << endl;
    cout << "\tTotal tips: " << driver.getTotalTips() << endl;
  }
  
  
  
  
  
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
  driver.deliver(time, tip);
  delivered.push_back(driver.getOrder());
}
