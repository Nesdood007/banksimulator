//bank.C file
//Amy Vinson and Brady O'Leary

#include <iostream>
#include "bank.h"
using namespace std;

//Constructers and Destructors

//Creates and opens teh bank.
Bank::Bank(const int& bad, const int& good, const int& man, const priority_queue<Item*, vector<Item*>, compareItem>& p) {
    badTellers = bad;
    goodTellers = good;
    managers = man;
    pq = p;
}

Bank::Bank(const Bank& ref) {
    
}

Bank::~Bank() {

}

//Functions
//Overridden from Item class
void Bank::run() {
    cout << "TESt" << endl;
}


