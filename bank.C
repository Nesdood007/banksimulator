//bank.C file
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "bank.h"
#include <stdlib.h>
#include <time.h>
#include "teller.h"
#include "customer.h"
#include "manager.h"
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
	    temp = new BadTeller(*this);
        pq->push(temp);
    }
    
    for(int i = 0; i < good; i++) {
        temp = new GoodTeller(*this);
        pq->push(temp);
    }
    
    for(int i = 0; i < man; i++) {
	    temp = new Manager(*this);
        pq->push(temp);
    }
    
    srandom(time(0));
    
    //Add some Customers
    //TODO Consider changing the way Customers are added
    for(int i = 0; i < NUMBEROFCUSTOMERS; i++) {
        temp = new Customer(random()%299 + 300, random()%599 + 600, customerList);//Sets tolerance time and transaction time
        //Assign Key: random between 0 and NUMBEROFCUSTOMERS
        int time = random()%timeBetweenCustomers + (i * timeBetweenCustomers);
        //cout << "Time is: " << time << endl;
        temp->setKey(time);
        pq->push(temp);
    }
    
    //cout << "PQSize: " << pq->size() << endl;
    
    satisfactionScore = 0;
    customersServed = 0;
    state = open;
    isManagerPresent = false;
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
    if(state == open && key >= CLOSINGTIME) {
        cout << "Bank is now Closed" << endl;
        //Make customers leave.
        
        while(!customerList.empty()) {
            customerList.pop_front();
            satisfactionScore -= 10;
        }
        
    } else {
        cout << "This shouldn't happen" << endl;
    }
}

//For Bank Score
void Bank::goodScore() {
    //cout << "Good Score" << endl;
    satisfactionScore += 10;
    customersServed++;
   
}

void Bank::badScore() {
    //cout << "Bad Score" << endl;
    satisfactionScore -= 10;
    customersServed++;
}

//So Customers can get in line
/*void Bank::putInLine(Customer& c) {
    Customer* temp = &c;
    cout << "Put in Line: " << temp << endl;
    customerList.push_back(&c);
}*/

int Bank::report() {
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Number of customers served: " << customersServed << endl;
    return 0;
}

/*Customer* Bank::getNextCustomer() {
    Customer* temp;
    if(!customerList.empty()) {
        temp = customerList.front();
        customerList.pop_front();
        return temp;
    }
    return NULL;
}*/

