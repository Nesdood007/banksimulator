//teller.h
//Amy Vinson and Brady O'Leary

#ifndef teller_H
#define teller_H
#include "item.h"
#include <iostream>
#include <list>
using namespace std;

//Will contain headers of Teller, GoodTeller, and BadTeller
class Teller : public Item {
    enum State {idle = 0, rest = -1, busy = 1};
    State state;
    
    public:
        Teller();
        Teller(const Teller&);
        ~Teller();
        
        virtual void run() {cout << "Shouldn't run Teller" << endl;};
};

class GoodTeller : public Teller {
    /*void GetGoodTeller(){
    Teller* GT = new Teller;
        if (GT->state = 0) {


        } else if (GT->state = -1) {

        } else if (GT->state = 1) {

        }
    } */
    
    public:
        GoodTeller() : Teller() {};
        GoodTeller(const GoodTeller&);
        ~GoodTeller();
        
        //Overridden function
        void run();
};

class BadTeller : public Teller {
    /*BadTeller BT = new BadTeller*;
    void GetBadTeller(){

        if (BT->state = 0) {
   
        } else if (BT->state = -1) {

        } else if (BT-> state = 1) {

        } 
    }*/
    
    public:
        BadTeller() : Teller() {};
        BadTeller(const BadTeller&);
        ~BadTeller();
        
        //Overridden Function
        void run();
};
#endif
