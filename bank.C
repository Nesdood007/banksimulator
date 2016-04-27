//bank.C file
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "bank.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

const int NUMBEROFCUSTOMERS = 10;
const int CLOSINGTIME = 28000;

//Constructers and Destructors

//Creates and opens teh bank.
Bank::Bank(const int& bad, const int& good, const int& man, priority_queue<Item*, vector<Item*>, compareItem>& p) {
    Customer* temp;
    //Calculate the maximum amount of time between customers
    int timeBetweenCustomers = CLOSINGTIME / NUMBEROFCUSTOMERS;

    badTellers = bad;
    goodTellers = good;
    managers = man;
    pq = &p;
    
    //Adds things to the Priority Queue
    for(int i = 0; i < bad; i++) {
        //TODO this might be the better way to add to the queue but it doesn't work yet.  I think we need to do teller before this will work
        //Teller BT = new BadTeller;
        //pq->push(BT);
        //cout << "Teller" << BT << endl;
    }
    
    for(int i = 0; i < good; i++) {
        //pq->push(new BadTeller);
    }
    
    for(int i = 0; i < man; i++) {
        //pq->push(new Manager);
    }
    
    srandom(time(0));
    
    //Add some Customers
    //TODO Consider changing the way Customers are added
    for(int i = 0; i < NUMBEROFCUSTOMERS; i++) {
        temp = new Customer;
        //Assign Key: random between 0 and NUMBEROFCUSTOMERS
        int time = random()%timeBetweenCustomers + (i * timeBetweenCustomers);
        cout << "Time is: " << time << endl;
        temp->setKey(time);
        pq->push(temp);
    }
    
    cout << "PQSize: " << pq->size() << endl;
    
    satisfactionScore = 0;
    customersServed = 0;
    state = open;
}

Bank::Bank(const Bank& ref) {
    badTellers = ref.badTellers;
    goodTellers = ref.goodTellers;
    managers = ref.managers;
    pq = ref.pq;
    customerList = ref.customerList;
}

Bank::~Bank() {

}

//Functions
//Overridden from Item class
void Bank::run() {
    if(state == open) {
        cout << "Bank is now Closed" << endl;
        //Make customers leave.
        report();
    } else {
        cout << "This shouldn't happen" << endl;
    }
}

//For Bank Score
void Bank::goodScore() {

}

void Bank::badScore() {
}

int Bank::report() {
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Number of customers served: " << customersServed << endl;
    return 0;
}


