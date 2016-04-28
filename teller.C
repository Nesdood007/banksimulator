//teller.C
//Brady O'Leary and Amy Vinson

#include "teller.h"
#include <iostream>
#include "customer.h"
#include <stdlib.h>

//Will have thing from Teller, GoodTeller, and BadTeller

//Teller Class
Teller::Teller() {
    state = idle;
    lastBreak = 0;
    bank = NULL;
    curr = NULL;
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
    cout << "GoodTeller Ran: " << this << endl;
    
    //Go home if after closing.
    if(key >=28000) return;
    
    if (state == idle) {
        //Take in Customer
        cout << "Is Empty: " << bank->customerList.empty() << endl;
        if(!bank->customerList.empty()) {
            helpCustomer();
        } else {
            //if not taken a break for 3600s, change state to rest for 300s. else go idle for 30s
            if(lastBreak + 3600 < key) {
                cout << "breaktime" << endl;
                lastBreak = key;
                state = rest;
                key += 300;
                bank->pq->push(this);
            } else {
                cout << "waiting..." << endl;
                key += 30;
                bank->pq->push(this);
            }
        }
    } else if (state == rest) {
        cout << "ToIdleFromRest" << endl;
        //Go Idle
        state = idle;
    } else {
        //busy state, release customer and do Bank Satisfaction Score
        if(curr != NULL) {
            cout << "Finished With Transaction: Customer was ";
            state = idle;
            if(curr->isSatisfied()) {
                cout << "satisfied" << endl;
                bank->goodScore();
            } else {
                cout << "unsatisfied" << endl;
                bank->badScore();
            }
            //delete curr;
        } else {
            cout << "This shouldn't happen" << endl;
        }
        
        if(!bank->customerList.empty()) {
            helpCustomer();
        } else {
            if(lastBreak + 3600 < key) {
                cout << "breaktime" << endl;
                lastBreak = key;
                state = rest;
                key += 300;
                bank->pq->push(this);
            } else {
                cout << "waiting..." << endl;
                key += 30;
                bank->pq->push(this);
            }
        }
    }
    
    cout << "Key is: " << key << endl;
    
}

void GoodTeller::helpCustomer() {
    curr = bank->customerList.front();
    cout << "Helping Customer: " << curr << endl;
    state = busy;
    key += curr->getTransactionTime();
    bank->pq->push(this);
}

//Bad Teller Class
BadTeller::BadTeller(Bank& b) {
    bank = &b;
    srandom(time(0));
}

BadTeller::BadTeller(const BadTeller&) {
    
}

BadTeller::~BadTeller() {
    
}

void BadTeller::run() {
    cout << "Bad Teller Ran" << endl;
    
    //Go home if after closing.
    if(key >=28000) return;
    
    if (state == idle) {
        //Take in Customer
        cout << "Is Empty: " << bank->customerList.empty() << endl;
        if(!bank->customerList.empty()) {
            //Do random case where BadTeller waits to help the customer
            if(random()%2 == 0) {
                cout << "Will wait for 30 seconds before helping customer" << endl;
                key += 60;
                bank->pq->push(this);
            } else {
                helpCustomer();
            }
            //change state to busy
        } else {
            //if not taken a break for 3600s, change state to rest for 300s. else go idle for 30s
            if(!bank->isManagerPresent) {
                cout << "breaktime" << endl;
                lastBreak = key;
                state = rest;
                key += 600;
                bank->pq->push(this);
            } else {
                cout << "waiting..." << endl;
                key += 60;
                bank->pq->push(this);
            }
        }
    } else if (state == rest) {
        //Go Idle
        state = idle;
        //check for customer in line
        //if no customer, change state to idle for 60s
        //if customer, dp transaction (2x time)
        if(!bank->customerList.empty()) {
            helpCustomer();
        } else {
            state = idle;
            key += 30;
            bank->pq->push(this);
        }
    } else {
        //busy state, release customer and do Bank Satisfaction Score
        if(curr != NULL) {
            cout << "Finished With Transaction: Customer was ";
            state = idle;
            if(curr->isSatisfied()) {
                cout << "satisfied" << endl;
                bank->goodScore();
            } else {
                cout << "unsatisfied" << endl;
                bank->badScore();
            }
            //delete curr;
        } else {
            cout << "This shouldn't happen" << endl;
        }
        
        if(key > lastBreak + 3600) {
            state = rest;
            key += 600;
            bank->pq->push(this);
        } else {
            if(random()%2 == 0) {
                cout << "BadTeller is taking a small break" << endl;
                state = idle;
                key += 60;
                bank->pq->push(this);
            } else {
                helpCustomer();
            }
        }
    }
}

void BadTeller::helpCustomer() {
    curr = bank->customerList.front();
    bank->customerList.pop_front();
    cout << "Helping Customer: " << curr << endl;
    state = busy;
    key += curr->getTransactionTime() * 2;
    bank->pq->push(this);
}
