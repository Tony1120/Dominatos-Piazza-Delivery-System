//Jemal, Nick, Tony
//PizzaHub

#include <iostream>
#include "time.h"

#include "driver.h"
#include "order.h"
#include "restaurant.h"

using namespace std;

void test_Restaurant(Restaurant &restaurant);

int main(int argc, const char * argv[]) {
    Restaurant PizzaHub;
    PizzaHub.addDriver("Nick");
    PizzaHub.addDriver("Tony");
    PizzaHub.addDriver("Jemal");
    PizzaHub.getDriver("Tony")->login();
    
    
    Time testTime = Time(10,20);
    cout << testTime.toString() << endl;
    Order newOrder(testTime, "2 Cheese to Taylor Hall");
    
    PizzaHub.addOrder(newOrder);
    
    test_Restaurant(PizzaHub);


    
    return 0;
}


void print_help(){
    cout << endl << "Commands:" << endl;
    cout << "  H                       : Help (displays this message)" << endl;
    cout << "  login DRIVER            : Logs in the driver" << endl;
    cout << "  logout DRIVER           : Logs out the driver" << endl;
    cout << "  order TIME INFO         : Creates an order with the time ordered and they type of pizza ordered" << endl;
    cout << "  serve TIME              : Order is done cooking and ready for delivery" << endl;
    cout << "  depart TIME DRIVER      : Driver is leaving to deliver the order" << endl;
    cout << "  deliver TIME DRIVER TIP : Driver has delived the order and recieved a tip (tip recieved can be zero)"<< endl;
    cout << "  arrive TIME DRIVER      : Driver has returned from delivering an order" << endl;
    cout << "  status                  : Used to view the status of orders and drivers" << endl;
    cout << "  summary                 : Used to view summary statistics on drivers and orders" << endl;
    cout << "  quit                    : Terminates the program" << endl;
    
    cout << endl;
}




void test_Restaurant(Restaurant &restaurant)
{
    // testFunction
    // Precondition: a Restaurant Object as input
    // Postcondition; test the method of the Restaurant Object
    
    
    
    
    int tip;
    string cmd;                   // Input command
    string driver_name;
    string order_info; //
    print_help();

    cout << "Command: ";
    while (cin>>cmd&&cmd!="quit") {

        if ( cmd == "login"  ){
            cin >> driver_name;
            cout << "Driver name: " << driver_name << endl;
        }
        
        else if (  cmd == "logout" ){
            cin >> driver_name;
        }
        
        else if ( cmd == "serve" ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
        }
        
        else if ( cmd == "order"  ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> order_info;
        }
        
        else if ( cmd == "depart"|| cmd == "arrive" ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> driver_name;
        }
        
        else if ( cmd == "deliver" ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> driver_name;
            cin >> tip;
        }
        
        else if ( cmd == "h"  ){
            print_help();
        }
        cout << endl << "Command: ";
    }

}
