//customer.h file for bank simulator
//Brady O'Leary and Amy Vinson
//CSCE 240 Project 7

#ifndef customer_H
#define customer_H
#include "item.h"
#include <iostream>
#include <list>
using namespace std;

class Customer : public Item {
    
    int toleranceTime;
    int transactionTime;

    public:
        Customer();
        Customer(const Customer&);
        ~Customer();
        
        //Gets the transaction time of the Customer.
        int getTransactionTime();
        
        //Overriden function
        void run();
};
#endif
