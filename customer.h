//customer.h file for bank simulator
//Brady O'Leary and Amy Vinson
//CSCE 240 Project 7

#ifndef customer_H
#define customer_H
#include "item.h"
#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;

class Customer : public Item {
    
    int toleranceTime;
    int transactionTime;
    
    //Start with State Normal, then change to State satisfied whent he customer enters the bank, then change to State notSatisfied if the customer is not served in time.
    enum State {normal = 0, satisfied = 1, notSatisfied = 2};
    
    State state;
    
    list<Customer*>* line;

    public:
        Customer();
        Customer(int t, int r, list<Customer*>& l);
        Customer(list<Customer*>& l);
        Customer(const Customer& ref);
        ~Customer();
        
        //Gets the transaction time of the Customer.
        int getTransactionTime();
        
        //Tells whether the customer is satisfied.
        bool isSatisfied();
        
        //Overriden function
        void run();
};
#endif
