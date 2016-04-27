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
   public:
    enum state {idle = 0, rest = -1, busy = 1};

};

class GoodTeller : public Teller {
    /*void GetGoodTeller(){
    Teller* GT = new Teller;
        if (GT->state = 0) {


        } else if (GT->state = -1) {

        } else if (GT->state = 1) {

        }
    } */ 
    
};

class BadTeller : public Teller {
    /*BadTeller BT = new BadTeller*;
    void GetBadTeller(){

        if (BT->state = 0) {
   
        } else if (BT->state = -1) {

        } else if (BT-> state = 1) {

        } 
    }*/
};
#endif
