//teller.C
//Brady O'Leary and Amy Vinson

#include "teller.h"
#include <iostream>
#include "customer.h"
#include "bank.h"

//Will have thing from Teller, GoodTeller, and BadTeller

//Teller Class
Teller::Teller() {
    state = idle;
}

Teller::Teller(const Teller& ref) {
    
}

Teller::~Teller() {
    
}

//Good Teller Class
/*GoodTeller::GoodTeller(priority_queue<Item*, vector<Item*>, compareItem>& p) {
    pq = &p;
}*/

GoodTeller::GoodTeller(const GoodTeller& ref) {
    
}

GoodTeller::~GoodTeller() {
    
}

void GoodTeller::run() {
    Customer* curr;
    cout << "GoodTeller Ran" << endl;
    
    if (state == idle) {
        //Take in Customer
        //curr = Bank::getNextCustomer();
        curr = new Customer;
        cout << "USING DUMMY CUSTOMER" << endl;
        
        if(curr != NULL) {
            state = busy;
            key += curr->getTransactionTime();
            //pq->push(this);
            //change state to busy
        } else {
            //if not taken a break for 3600s, change state to rest for 300s. else go idle for 30s
        }
    } else if (state == rest) {
        
        //Go Idle
    } else {
        //busy state, release customer and do Bank Satisfaction Score
    }
    
}

//Bad Teller Class
/*BadTeller::BadTeller(priority_queue<Item*, vector<Item*>, compareItem>& p) {
    pq = &p;
}*/

BadTeller::BadTeller(const BadTeller&) {
    
}

BadTeller::~BadTeller() {
    
}

void BadTeller::run() {
    cout << "Bad Teller Ran" << endl;
    
}
