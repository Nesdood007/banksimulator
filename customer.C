//customer.C for bank simulator
//Amy Vinson and Brady O'Leary

#include "customer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constructors and Desctructors
Customer::Customer() {
    srandom(time(0));
    toleranceTime = random()%299 + 300;
    transactionTime = random()%599 + 600;
}

Customer::Customer(const Customer& ref) {
    
}

Customer::~Customer() {
    
}

//Functions
int Customer::getTransactionTime() {
    return transactionTime;
}

void Customer::run() {
    cout << "Customer Ran around with his hair on fire." << endl;
}
