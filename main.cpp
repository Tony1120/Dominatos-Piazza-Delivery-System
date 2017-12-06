//Jemal, Nick, Tony
//PizzaHub

#include <iostream>
#include "time.h"

#include "driver.h"
#include "order.h"
#include "restaurant.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello World" << endl;
    
    Restaurant PizzaHub;

//    Time(12,00)
//    Order(,)
    
    PizzaHub.addDriver("Nick");
    
//    cout<<" status"<<endl;
//    PizzaHub.status();
//    cout<<" summary"<<endl;
//    PizzaHub.summary();
    
    
    
    PizzaHub.addDriver("Tony");
    PizzaHub.addDriver("Jemal");
    
    PizzaHub.getDriver("Ton")->login();
    
    Order newOrder(Time(11,50), "2 Cheese to Taylor Hall");
    PizzaHub.addOrder(newOrder);

    cout<<" status"<<endl;
    PizzaHub.status();
    cout<<" summary"<<endl;
    PizzaHub.summary();
    
    return 0;
}
