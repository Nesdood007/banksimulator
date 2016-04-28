//teller.C
//Brady O'Leary and Amy Vinson

#include "teller.h"
#include <iostream>
#include "customer.h"

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
GoodTeller::GoodTeller(Bank& b) {
    bank = &b;
}

GoodTeller::GoodTeller(const GoodTeller& ref) {
    
}

GoodTeller::~GoodTeller() {
    
}

void GoodTeller::run() {
    Customer* curr;
    cout << "GoodTeller Ran" << endl;
    
    if (state == idle) {
        //Take in Customer
        curr = bank->getNextCustomer();
        if(curr != NULL) {
            state = busy;
            key += curr->getTransactionTime();
            bank->pq->push(this);
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
BadTeller::BadTeller(Bank& b) {
    bank = &b;
}

BadTeller::BadTeller(const BadTeller&) {
    
}

BadTeller::~BadTeller() {
    
}

void BadTeller::run() {
    cout << "Bad Teller Ran" << endl;
    
}
