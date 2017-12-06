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
    
    
    Time testTime = Time(10,20);
    cout << testTime.toString() << endl;
    
    Order newOrder(testTime, "2 Cheese to Taylor Hall");
    
    
    
    PizzaHub.addOrder(newOrder);
    


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


void print_help(){
    // Print_help
    // precondition: none
    // Postcondition: print the help for the test function
    cout << endl << "Commands:" << endl;
    cout << "  H  : Help (displays this message)" << endl;
    cout << "  Fx : Print the outcome of the HashFunction for the key x" << endl;
    cout << "  +x : Insert x as a key to the HashTable" << endl;
    cout << "  -x : Remove all xs in the HashTable" << endl;
    //    cout << "  C  : Clear the Hashtable" << endl;
    cout << "  ?x : Is the key x in HashTable?" << endl;
    cout << "  Ix : retrive the index of the key x in the HashTable" << endl;
    cout << "  Ci : print Collisons in the i line of the HashTable"<< endl;
    cout << "  Q  : Quit the test program" << endl;
    cout << endl;
}





void test_Restaurant(Restaurant &restaurant)
{
    // testFunction
    // Precondition: a Restaurant Object as input
    // Postcondition; test the method of the Restaurant Object
    
    string cmd;                   // Input command
    string testData;              // HashTable data item
    
    print_help();
    
    do
    {
        try {
            cout<< testHash;                    // Output queue
            
            cout << endl << "Command: ";                  // Read command
            cin >> cmd;
            if ( cmd == '+'  ||  cmd == 'F'|| cmd == 'f'|| cmd == '-'||  cmd == 'I'||cmd == 'i'||  cmd == 'C'||  cmd == 'c'||cmd == '?' )
                cin >> testData;
            
            switch ( cmd )
            {
                case 'H' : case 'h' :
                    
                    print_help();
                    break;
                    
                case 'F' : case 'f' :                                  // hashfunction
                    cout <<endl;
                    cout << "Index for " << testData<< " will be " <<testHash.hashFunction(testData)<< endl;
                    break;
                    
                case '+' :                                  // insert
                    cout << "Insert " << testData << endl;
                    testHash.insert(testData);
                    break;
                    
                case '-' :                                  // remove
                    cout << "Remove " << testData << endl;
                    testHash.removeKey(testData);
                    
                    break;
                    
                case '?' :                                  // isKeyInTable
                {
                    cout<< endl;
                    bool isin = testHash.isKeyInTable(testData);
                    if (isin) {
                        cout<<"the key "<< testData<<" is in the HashTable"<<endl;
                    }
                    else cout << "the key is not in the HashTable"<<endl;
                    break;
                }
                case 'I' : case 'i' :                       // Retrive the index of key
                {
                    int IndexForKey=testHash.retrieveKey(testData);
                    cout <<endl;
                    cout <<"the index for the key "<<testData<<" is: "<< IndexForKey<<endl;
                    break;
                }
                case 'C' : case 'c' :                       // Retrive the index of key
                {
                    int index = stoi(testData);
                    cout<<"the collisons in the line "<<index<<" is "<<testHash.printCollisons(index)<<endl;
                    break;
                }
                    
                case 'Q' : case 'q' :                   // Quit test program
                    break;
                    
                default :                               // Invalid command
                    cout << "Inactive or invalid command" << endl;
            }
        }
        catch (logic_error e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    while ( cin && cmd != 'Q'  &&  cmd != 'q' );
    
    if( !cin ) {
        cout << "input error" << endl;
    }
    
}

