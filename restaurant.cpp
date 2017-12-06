
#include "restaurant.h"



using namespace std;

Restaurant::Restaurant(){
  list<Driver> drivers;           // empty list of drivers
  list<Order> delivered;         // emptry list of delivered pizza
  deque<Order> toCook;          // empty list of food waiting to be cooked
  deque<Order> served;        //orders waiting to be delivered (departure)?
                            // what else do we need in the constructor??
}

void Restaurant::status(){
  cout << "Orders waiting to cook: " << endl;
    
  for( auto &cookItr : toCook){
    cout << '\t' << cookItr.toString() << endl;
  }

  cout << "Orders waiting to depart: " << endl;
  for( auto &serveItr : served){
    cout << '\t' << serveItr.toString() << endl;
  }

  cout << "Drivers: " << endl;
  for( auto &driverItr : drivers){
    cout << '\t' << driverItr.toString() << endl;
  }
        cout<<endl;
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

    float average_time_per_order;
    
    if (completed==0) {
        average_time_per_order=0;
    }
    else{
        average_time_per_order=totalTime/completed;
    }
  cout << "Average time per order: ";
  cout << average_time_per_order << endl;
    cout << endl;
    //use a for loop that goes through the list of drivers
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

//    for (deque<Order>::iterator it = toCook.begin(); it!=toCook.end(); ++it){
//        cout <<  << *it;
//
//    }


Driver * Restaurant::getDriver(string name){
  for(list<Driver>::iterator it = drivers.begin(); it != drivers.end(); ++it ){
    if(it->getName() == name){
      return &*it;
    }
  }
  return nullptr;
}

    
void Restaurant:: addDriver(string name){
//    drivers.push_back(driver);
    drivers.push_back(Driver(name));

}
    


void Restaurant::addOrder( Order & order){
    toCook.push_back(order);
}

void Restaurant::serveNextOrder() throw (logic_error){
  if(toCook.empty()){
    throw logic_error("There are no pizza's being cooked ");
  }
    
    
    Order serve_order= toCook.front();
    toCook.pop_front();
    served.push_back(serve_order);
}

Order * Restaurant::departNextOrder() throw (logic_error){
    if (served.empty()) {
        throw logic_error("There are no pizza ready to be delivered ");
    }
    
    Order order_depart = served.front();
    served.pop_front();
    
    Order *order_depart_ptr=&order_depart;
    
  return order_depart_ptr;
}

void Restaurant::deliver(Driver & driver, Time time, float tip){
  driver.deliver(time, tip);
    delivered.push_back(*driver.getOrder());
}
