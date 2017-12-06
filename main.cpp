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
    Driver Nick("Nick");
//    Driver &NickRef = Nick;
    Driver Jemal("Jemal");
    Driver Tony("Tony");

//    Time(12,00)
//    Order(,)
    
    PizzaHub.addDriver(Nick);
    
//    cout<<" status"<<endl;
//    PizzaHub.status();
//    cout<<" summary"<<endl;
//    PizzaHub.summary();
    
    
    
    PizzaHub.addDriver(Tony);
    PizzaHub.addDriver(Jemal);
    
    Nick.login();
    string test=Nick.toString();
    cout<<" status"<<endl;
    PizzaHub.status();
    cout<<" summary"<<endl;
    PizzaHub.summary();
    

    
    
    
    return 0;
}
