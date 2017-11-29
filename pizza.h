

































































class OrderP{
public:

    //Post: Creates an order with default values for data members.
    Order();
   
    //Post: Creates an order with the given order time and information.
    Order(Time time, string info);


    
    //Pre: Order is at the restaurant.
    //Post: Order is out for delivery.
    void depart() throw (logic_error)
    
    //Pre: Order is out for delivery.
    //Post: Order is delivered. Time to delivery is recorded.
    void deliver(Time time) throw (logic_error)

    
    //Pre: Order is delivered.
    //Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
    int getMinToDelivery() throw (logic_error)
    
    
    //Post: Returns a string containing the order time and info.
    string toString()
    
    
    
private:
};




class Time(){
public:
    
    //Post: Creates a time with default values for data members.
    Time();

    //Pre: 0 <= hour <= 23 and 0 <= min <= 59.
    //Post: Creates a time with the given hour and minute.
    Time(int hour, int min) throw (logic_error);
    
    //Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
    static int elapsedMin(Time t1, Time t2);
    
    //Post: Returns a string containing the hour and minute (e.g., “13:01”).
    string toString();
    
private:
    
};










