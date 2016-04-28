//bank.C file
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "bank.h"
#include <stdlib.h>
#include <time.h>
#include "teller.h"
#include "customer.h"
using namespace std;

const int NUMBEROFCUSTOMERS = 10;
const int CLOSINGTIME = 28000;

//Constructers and Destructors

//Creates and opens teh bank.
Bank::Bank(const int& bad, const int& good, const int& man, priority_queue<Item*, vector<Item*>, compareItem>& p) {
    Item* temp;
    //Calculate the maximum amount of time between customers
    int timeBetweenCustomers = CLOSINGTIME / NUMBEROFCUSTOMERS;

    badTellers = bad;
    goodTellers = good;
    managers = man;
    pq = &p;
    
    //add things to the queue

    for(int i = 0; i < bad; i++) {
	    temp = new BadTeller(*pq);
        pq->push(temp);
    }
    
    for(int i = 0; i < good; i++) {
        temp = new GoodTeller(*pq);
        pq->push(temp);
    }
    
    for(int i = 0; i < man; i++) {
	//temp = new Manager(*pq);
        //pq->push(temp);
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
    //customerList = ref.customerList;
}

Bank::~Bank() {

}

//Functions
//Overridden from Item class
void Bank::run() {
    if(state == open) {
        cout << "Bank is now Closed" << endl;
        //Make customers leave.
	//removeCustomers();
        report();
    } else {
        cout << "This shouldn't happen" << endl;
    }
}

//For Bank Score
void Bank::goodScore() {
   satisfactionScore += 10; 
}

void Bank::badScore() {
  satisfactionScore -= 10; 
}

//So Customers can get in line
void Bank::putInLine(Customer& c) {
    Customer* temp = &c;
    cout << "Put in Line: " << temp << endl;
    //customerList.insert(&c);
}

int Bank::report() {
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Number of customers served: " << customersServed << endl;
    return 0;
}


