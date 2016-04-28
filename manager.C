//manager.C
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "manager.h"
#include "item.h"
#include "bank.h"

using namespace std;

void Manager::Run() {
    Customer* curr;
    if (state == office) {
        state = visit;
        //cur = Bank::getNextCustomer();
        curr = new Customer;
        cout << "USING DUMMY CUSTOMER - MANAGER" << endl;

        if (curr != NULL) {
            key += curr->getTransactionTime();
            //pq->push(this);

        }
        state = office;
    } else return;


    
}
