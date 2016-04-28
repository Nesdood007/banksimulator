//manager.h
//Brady O'Leary and Amy Vinson

#ifndef manager_H
#define manager_H
#include "item.h"
#include <list>
#include <iostream>
#include "bank.h"
using namespace std;

class Manager : public Item {

    enum State {office = 0, visit = 1};
    State state;
    
    Bank* bank;
    
    Customer* curr;

    public:
    
    Manager(Bank& b);
    Manager(const Manager& ref);
    ~Manager();
    //overiding Item function "run()"
    void run();

    //returns the state of the manager
   // void  getManagerState();














};
#endif
