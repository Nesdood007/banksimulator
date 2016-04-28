//customer.C for bank simulator
//Amy Vinson and Brady O'Leary

#include "customer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructors and Desctructors
Customer::Customer() {
    srandom(time(NULL));
    toleranceTime = random()%299 + 300;
    transactionTime = random()%599 + 600;
    state = normal;
    cout << "Customer Created|toleranceTime: " << toleranceTime << " Transaction Time: " << transactionTime << endl;
}

Customer::Customer(int tolerance, int transaction) {
    //bank = &b;
    toleranceTime = tolerance;
    transactionTime = transaction;
    state = normal;
    cout << "Customer Created|toleranceTime: " << toleranceTime << " Transaction Time: " << transactionTime << endl;
}
//Customer::Customer(const Bank& b) {
  //  bank = &b;
//}

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
    cout << "Customer Ran around with his hair on fire." << endl;
    if(state == normal) {
        cout << "Customer entered bank." << endl;
        state = satisfied;
        Bank::putInLine(*this);
    } else if(state == satisfied) {
	
         cout << "Customer was not served on time. Customer is now pissed." << endl;
         state = notSatisfied;
    }
    
    
}

bool Customer::isSatisfied() {
    return state == satisfied;
}


