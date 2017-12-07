//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           main.cpp
//
//  Test program for the Pizza Tracking System
//
//--------------------------------------------------------------------


#include <iostream>
#include "time.h"
#include "driver.h"
#include "order.h"
#include "restaurant.h"
#include "levenshtein.h"

using namespace std;

//Set to false to turn off spellcheck features
const bool spellcheck = true;

void test_Restaurant(Restaurant &restaurant);
void print_help();

int main() {
    Restaurant PizzaHub;
    float tip;
    string cmd;				//Input command
    string driver_name;
    string order_info;
    print_help();

    cout << "Command: ";
    while (cin>>cmd&&cmd!="quit") {
		// Spellcheck feature checks the command 
        if(spellcheck){
            //Check the command is valid
            if(!isValidCommand(cmd))
                //If not guess it
                cmd = guessCommand(cmd);
        }

        //If cmd is blank print an error
        if(cmd == "")
            cout << "Please enter a valid command, or type 'help' for help" << endl;

        //Login
        if ( cmd == "login"  ){
            cin >> driver_name;
			//Driver is added
            PizzaHub.addDriver(driver_name);
			// Driver is logged in
            PizzaHub.getDriver(driver_name)->login();
        }

        //Logout
        else if (cmd == "logout"){
            cin >> driver_name;
            Driver * temp = PizzaHub.getDriver(driver_name);
			// Check if the driver exists before logout
            try{
                if(temp != nullptr){
                    temp->logout();
                }else{
                    cout << "Driver " << driver_name << " does not exist" << endl;;
                }
            }catch(logic_error& e){
                cout << e.what() << endl;
            }
        }

        //Serve the next order
        else if (cmd == "serve"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1); //Ignore the separator
            cin >> min;
            try{
                PizzaHub.serveNextOrder();
            }catch(logic_error& e){
                cout << e.what() << endl;
            }

        }

        //Add an order to the system
        else if (cmd == "order"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin.ignore(1); //ignore the separator
			//Gets order info from cmd 
            getline(cin, order_info);
			//Makes a new order
            Order newOrder = Order(Time(hour, min), order_info);
			//Adds order to deque
            PizzaHub.addOrder(newOrder);
        }

        //Driver depart
        else if (cmd == "depart"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1); //ignore the separator
            cin >> min;
            cin >> driver_name;
            Order to_depart = PizzaHub.departNextOrder();
            PizzaHub.getDriver(driver_name)->depart(Time(hour, min), to_depart);
        }

        //Driver arrive
        else if (cmd == "arrive"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1); //ignore the separator
            cin >> min;
            cin >> driver_name;
            try{
                PizzaHub.getDriver(driver_name)->arrive(Time(hour, min));
            }catch(logic_error& e){
                cout << e.what() << endl;
            }
        }

		//Deliver an order
        else if ( cmd == "deliver" ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1); //ignore the separator
            cin >> min;
            cin >> driver_name;
            cin >> tip;
            try{
                PizzaHub.getDriver(driver_name)->deliver(Time(hour, min), tip);
            }catch(logic_error& e){
                cout << e.what() << endl;
            }
        }

        //Get restaurant status
        else if ( cmd == "status" ){
            PizzaHub.status();
        }

        //Get restaurant summary
        else if ( cmd == "summary" ){
            PizzaHub.summary();
        }

        //Get help
        else if ( cmd == "help"  ){
            print_help();
        }
		// if command doesnt exist
        else{
            cout << "Command not found" << endl;
            print_help();
        }
        cout << "Command: ";

    }//end while
    return 0;
}//end main

void print_help(){
    cout << endl << "Commands:" << endl;
    cout << "  help                       : Help (displays this message)" << endl;
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
