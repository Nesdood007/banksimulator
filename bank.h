//bank.h file
//Amy Vinson and Brady O'Leary

#ifndef bank_H
#define bank_H
#include <iostream>
#include "item.h"
#include <list>
#include "customer.h" 
using std::list;
using namespace std;

class Bank : public Item {
    //Number of badTellers, goodTellers, and managers
    int badTellers;
    int goodTellers;
    int managers;

    int customersServed;
    int satisfactionScore;
    
    //Queue of customers
    list<Customer*> customerList;
    
    priority_queue<Item*, vector<Item*>, compareItem>* pq;
    
    enum State {closed = 0, open = 1};
    State state;
    
    public:
        //Creates and 'opens' the Bank
        Bank(const int& bad, const int& good, const int& man, priority_queue<Item*, vector<Item*>, compareItem>& p);
        Bank(const Bank&);
        ~Bank();
        
        //Overriding Item function "run()"
        void run();
        //void setKey(const int&);
        
        //Gets next Customer. returns NULL if no more customers
        Customer* getNextCustomer();

        
        
        //Bank satisfaction score
        static void goodScore();
        static void badScore();
        //return the score of the bank
        int report();
};

#endif
