//customer.C for bank simulator
//Amy Vinson and Brady O'Leary

#include "customer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include "bank.h"
using namespace std;

//Constructors and Desctructors
Customer::Customer() {
    srandom(time(NULL));
    toleranceTime = random()%299 + 300;
    transactionTime = random()%599 + 600;
    state = normal;
    cout << "Customer Created|toleranceTime: " << toleranceTime << " Transaction Time: " << transactionTime << endl;
}

Customer::Customer(int tolerance, int transaction, list<Customer*>& l) {
    toleranceTime = tolerance;
    transactionTime = transaction;
    line = &l;
    state = normal;
    cout << "Customer Created|toleranceTime: " << toleranceTime << " Transaction Time: " << transactionTime << endl;
}

Customer::Customer(list<Customer*>& l) {
  line = &l;
}

Customer::Customer(const Customer& ref) {
    
}

Customer::~Customer() {
    
}

//Functions
int Customer::getTransactionTime() {
    return transactionTime;
}

//overridden function
void Customer::run() {
    
    if(state == normal) {
        //cout << "Customer entered bank." << endl;
        cout << "Customer Ran around with his hair on fire." << endl;
        state = satisfied;
        //cout << "Customer is: " << this << endl;
        line->push_back(this);
    } else if(state == satisfied) {
	
         cout << "Customer was not served on time. Customer is now unsatisfied." << endl;
         state = notSatisfied;
    }
}

bool Customer::isSatisfied() {
    return state == satisfied;
}
