//bank.h file
//Amy Vinson and Brady O'Leary

#ifndef bank_H
#define bank_H
#include <iostream>
using namespace std;

class Bank : public Item {
    //Number of badTellers, goodTellers, and managers
    int badTellers;
    int goodTellers;
    int managers;
    
    int satisfactionScore = 0;
    int customersServed = 0;
    //Queue of customers
    list<Customer*> customerList;
    
    enum state {closed = 0, open = 1};
    
    public:
        //Creates and 'opens' the Bank
        Bank(const int& bad, const int& good, const int& man, priority_queue<Item*, vector<Item*>, compareItem>* pq);
        Bank(const Bank&);
        ~Bank();
        
        //Overriding Item function "run()"
        void run();
        
        //Gets next Customer
        Customer* getNextCustomer();
        
        //Gives the report on the Bank satisfaction score
        void report();
}

#endif
