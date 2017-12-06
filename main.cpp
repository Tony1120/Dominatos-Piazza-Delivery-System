//Jemal, Nick, Tony
//PizzaHub

#include <iostream>
#include "time.h"

#include "driver.h"
#include "order.h"
#include "restaurant.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Restaurant PizzaHub;
    PizzaHub.addDriver("Nick");
    PizzaHub.addDriver("Tony");
    PizzaHub.addDriver("Jemal");
    PizzaHub.getDriver("Tony")->login();
    
    Order newOrder(Time(11,50), "2 Cheese to Taylor Hall");
    PizzaHub.addOrder(newOrder);
    
    Time testTime = Time(10,20);
    cout << testTime.toString() << endl;

    cout<<"Status:"<<endl;
    PizzaHub.status();
    cout<<"Summary:"<<endl;
    PizzaHub.summary();
    
    string input;
    string commandInfo;
    string commandType;
    while(cin >> input && input !="q"){
        //Split input string
        
    }
    
    return 0;
}
