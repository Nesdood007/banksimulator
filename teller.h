//teller.h
//Amy Vinson and Brady O'Leary

#ifndef teller_H
#define teller_H
#include "item.h"
#include <iostream>
#include <list>
#include "bank.h"
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
        
        friend class GoodTeller;
        friend class BadTeller;
        
};

class GoodTeller : public Teller {
    /*void GetGoodTeller(){
    Teller* GT = new Teller;
        if (GT->state = 0) {


        } else if (GT->state = -1) {

        } else if (GT->state = 1) {

        }
    } */
    
    Bank* bank;
    
    public:
        //GoodTeller(priority_queue<Item*, vector<Item*>, compareItem>& p) : Teller() {pq = &p;};
        GoodTeller(Bank&);
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
    
    priority_queue<Item*, vector<Item*>, compareItem>* pq;
    
    public:
        BadTeller(priority_queue<Item*, vector<Item*>, compareItem>& p) : Teller() {pq = &p;};
        BadTeller(const BadTeller&);
        ~BadTeller();
        
        //Overridden Function
        void run();
};
#endif
