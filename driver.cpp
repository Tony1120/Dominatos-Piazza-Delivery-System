//--------------------------------------------------------------------
//   Jemal, Nick, Tony
//   PizzaHub
//
//  Final Project                                           driver.cpp
//
//  Implimentation for the driver class
//
//--------------------------------------------------------------------

#include "driver.h"
using namespace std;

/*
 * Preconditions: None
 * Postcondition: Constructor. Creates a logged-in driver with the given name.
 */
Driver::Driver(string name){
    driver_Name=name;
    
    depart_flag=false;
    deliver_flag=false;
    arrive_flag=false;
    login_flag = false;
    
    total_tips=0;
    total_deliveries=0;
    tot_mins_spent_driving=0;
    tot_mins_spent_delivering=0;
    
}

/*
 * Preconditions: Driver is not logged in.
 * Postcondition: Logs the driver in.
 */
void Driver:: login() throw(logic_error){
    if (login_flag==true) {
        throw logic_error("Driver has already logged in");
    }
    login_flag = true;
    arrive_flag= true;
    at_restaurant = true;
}

/*
 * Preconditions: Driver is logged in and at the restaurant.
 * Postcondition: Logs the driver out.
 */
void Driver:: logout() throw(logic_error){
    if (login_flag==false) {
        throw logic_error("Driver has already logged out");
    }
    
    login_flag = false;
    arrive_flag= false;
}

/*
 * Preconditions: Driver is logged in and at the restaurant.
 * Postcondition: Driver is delivering. Departure time is recorded.
 */
void Driver::depart(Time time, Order o) throw(logic_error){
    if (login_flag==false||arrive_flag==false) {
        throw logic_error("Driver is not logged in or not at the restaurant");
    }
    currentOrder = o; // past parameter o to currentOrder
    depart_flag = true;
    arrive_flag = false;
    depart_time = time;
    at_restaurant = false;
    
    currentOrder.depart(); // change the status of the order to depart
    
}

/*
 * Preconditions: Driver is delivering with a tip >= 0
 * Postcondition: Driver is not delivering. Driver’s stats are updated.
 */
Order Driver::deliver(Time time, float tip) throw(logic_error){
    
    if (deliver_flag==false && arrive_flag==false && tip>=0) {
        currentOrder.deliver(time);// change the status of the order to deliver
        
        deliver_flag=true;
        total_tips = total_tips+tip;
        deliver_time = time;
        
        tot_mins_spent_delivering= Time::elapsedMin(depart_time, deliver_time);
        
        total_deliveries = total_deliveries+1;
        return currentOrder;
    }
    else
        throw logic_error("driver is not delivering or the tip is less than 0");

}

/*
 * Preconditions: Driver is driving but not delivering.
 * Postcondition: Driver is at the restaurant. Driver’s stats are updated
 */
void Driver::arrive(Time time) throw(logic_error){
    if (arrive_flag==false&&deliver_flag==true) {
        at_restaurant = true;
        arrive_flag= true;
        deliver_flag=false;
        depart_flag = false;
        
        arrive_time=time;
        
        tot_mins_spent_driving=  Time::elapsedMin(depart_time, arrive_time);
    }
    else throw logic_error("driver is at the restaurant or is delivering");
}

/*
 * Preconditions: None
 * Postcondition: Returns the drivers name
 */
string Driver::getName(){
    return driver_Name;
}

/*
 * Preconditions: None
 * Postcondition: returns true if driver is logged in. Returns false otherwise
 */
bool Driver::isLoggedIn(){
    if (login_flag==true) {
        return true;
    }
    return false;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total number of completed deliveries.
 */
int Driver::getTotalDeliveries(){
    return total_deliveries;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total minutes spent delivering (i.e., between
 *                “depart” and “deliver” commands).
 */
int Driver::getTotalMinDelivering(){
    return tot_mins_spent_delivering;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total minutes spent driving (i.e., between
 *                “depart” and “arrive” commands).
 */
int Driver::getTotalMinDriving(){
    return tot_mins_spent_driving;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total tips received, in dollars
 */
float Driver:: getTotalTips(){
    return total_tips;
}

/*
 * Preconditions: Driver is delivering.
 * Postcondition: Returns the order being delivered.
 */
Order * Driver::getOrder() throw(logic_error){
    if (arrive_flag!=false&&deliver_flag!=false){
        throw logic_error("no order is carried by the driver");
    }
    
    Order *orderptr = &currentOrder;
    return orderptr;
}

/*
 * Preconditions: None
 * Postcondition: Returns a string containing the driver’s name, state
 *                (e.g., not logged in), and, if the driver is delivering an
 *                order, the departure time and toString of the order being delivered.
 */
string Driver::toString(){
    string loginstatus;
    
    if(login_flag==true) { // driver is logged in
        loginstatus = " ";
        if(at_restaurant)
            loginstatus=" is logged in ";
        if(arrive_flag==false) { // driver is out delivering order
            if(!deliver_flag)
                return driver_Name+loginstatus+currentOrder.toString();
            else
                return driver_Name + " is returning from a delivery";
        }
        else { // driver is at the restaurant
            return driver_Name+loginstatus.append("and currently at the restaurant");
        }
    }
	if(login_flag == false) {
		loginstatus = " is not logged in"; // driver
	}
    return driver_Name.append(loginstatus);
}






