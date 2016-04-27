//teller.C
//Brady O'Leary and Amy Vinson

#include "teller.h"

//Will have thing from Teller, GoodTeller, and BadTeller

//Teller Class
Teller::Teller() {
    state = idle;
}

Teller::Teller(const Teller& ref) {
    
}

Teller::~Teller() {
    
}

//Good Teller Class
GoodTeller::GoodTeller(const GoodTeller& ref) {
    
}

GoodTeller::~GoodTeller() {
    
}

void GoodTeller::run() {
    cout << "GoodTeller Ran" << endl;
}

//Bad Teller Class
BadTeller::BadTeller(const BadTeller&) {
    
}

BadTeller::~BadTeller() {
    
}

void BadTeller::run() {
    cout << "Bad Teller Ran" << endl;
    
}
