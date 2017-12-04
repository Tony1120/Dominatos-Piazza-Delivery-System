

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
    login_flag =true;
    arrive_flag= true;
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
void Driver :: depart(Time time, Order o) throw(logic_error){
    if (login_flag==false||arrive_flag==false) {
        throw logic_error("the driver is not logged in or not at the restaurant");
    }
    currentOrder = o;
    depart_flag= true;
    
    depart_time = time.get_min_time();
    
    departimeToString= time.toString();
}

/*
 * Preconditions: Driver is delivering with a tip >= 0
 * Postcondition: Driver is not delivering. Driver’s stats are updated.
 */
void Driver::deliver(Time time, float tip) throw(logic_error){
    
    if (deliver_flag==false&&arrive_flag==false&& tip>=0) {
        Order *temp = &currentOrder;
        delete temp; // not sure if it works
        
        
        deliver_flag=true;
        total_tips = total_tips+tip;
        last_deliver_time = time.get_min_time();
        
        tot_mins_spent_delivering= last_deliver_time - depart_time;
        
        total_deliveries = total_deliveries+1;
    }
    else throw logic_error("driver is not delivering or the tip is less than 0");

}

/*
 * Preconditions: Driver is driving but not delivering.
 * Postcondition: Driver is at the restaurant. Driver’s stats are updated
 */
void Driver::arrive(Time time) throw(logic_error){
    if (arrive_flag==false&&deliver_flag==true) {
        
        arrive_flag= true;
        deliver_flag=false;
        depart_flag = false;
        
        
        arrive_time=time.get_min_time();
        tot_mins_spent_driving= arrive_time - depart_time;
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
    if (login_flag=true) {
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
    
    
    if (login_flag==true) {
        loginstatus=" is logged in ";
        if (arrive_flag==false) {
            return driver_Name+loginstatus+departimeToString+currentOrder.toString(); \
        }
        return driver_Name+loginstatus.append("the driver is current at the restaurant");
        
    }
    
    loginstatus=" not logged in";
    return driver_Name.append(loginstatus);
}






