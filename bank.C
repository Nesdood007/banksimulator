//bank.C file
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "bank.h"
using namespace std;

const int NUMBEROFCUSTOMERS = 100;
const int CLOSINGTIME = 28000;

//Constructers and Destructors

//Creates and opens teh bank.
Bank::Bank(const int& bad, const int& good, const int& man, const priority_queue<Item*, vector<Item*>, compareItem>& p) {
    //Calculate the maximum amount of time between customers
    //int timeBetweenCustomers = CLOSINGTIME / NUMBEROFCUSTOMERS;

    badTellers = bad;
    goodTellers = good;
    managers = man;
    pq = p;
    
    //Adds things to the Priority Queue
    for(int i = 0; i < bad; i++) {
        //pq.push(new BadTeller);
    }
    
    for(int i = 0; i < good; i++) {
        //pq.push(new BadTeller);
    }
    
    for(int i = 0; i < man; i++) {
        //pq.push(new Manager);
    }
    
    //Add some Customers
    for(int i = 0; i < NUMBEROFCUSTOMERS; i++) {
        //Create Customer
        //Assign Key: random between 0 and NUMBEROFCUSTOMERS
        //pq.push(customer);
    }
    
    satisfactionScore = 0;
    customersServed = 0;
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
    cout << "TESt" << endl;
}

//For Bank Score
void Bank::goodScore() {

}

void Bank::badScore() {
}

void Bank::report() {
    cout << "OK" << endl;
}


