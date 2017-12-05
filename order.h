class Order{
public:

    //Post: Creates an order with default values for data members.
    Order();

    //Post: Creates an order with the given order time and information.
    Order(Time time, string info);

    //Pre: Nothing
    //Post: is_served = true.
    void serve();

    //Pre: Order is at the restaurant.
    //Post: Order is out for delivery.
    void depart() throw (logic_error);

    //Pre: Order is out for delivery.
    //Post: Order is delivered. Time to delivery is recorded.
    void deliver(Time time) throw (logic_error);

    //Pre: Order is delivered.
    //Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
    int getMinToDelivery() throw (logic_error);

    //Post: Returns a string containing the order time and info.
    string toString();

private:
    bool is_out_for_delivery;
    string order_info;
    bool is_served;            //has it been finished cooking?
    //bool has_left_restaurant; redundant because of is_out_for_delivery
    Time time_placed;
    Time time_delivered;

};
