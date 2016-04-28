//manager.C
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "manager.h"
#include "item.h"
#include "bank.h"

using namespace std;

Manager::Manager(Bank& b) {
    state = office;
    bank = &b;
    curr = NULL;
}

Manager::Manager(const Manager& ref) {

}

Manager::~Manager() {
    
}

void Manager::run() {
    cout << "Manager Ran: " << endl;
    
    //Quit if the bank is closed
    if(key >= 28000) return;
    
    if (state == office) {
        state = visit;
        bank->isManagerPresent = true;
        if (!bank->customerList.empty()) {
            curr = bank->customerList.front();
            bank->customerList.pop_front();
            cout << "Helping Customer: " << curr << endl;
            key += curr->getTransactionTime();
            bank->pq->push(this);
        }
    } else {
        state = office;
        bank->isManagerPresent = false;
        if(curr != NULL) {
            cout << "Customer was ";
            if(curr->isSatisfied()) {
                cout << "satisfied" << endl;
                bank->goodScore();
            } else {
                cout << "unsatisfied" << endl;
                bank->badScore();
            }
        } else {
            cout << "This shouldn't happen" << endl;
        }
    }
}
