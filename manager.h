//manager.h
//Brady O'Leary and Amy Vinson

#ifndef manager_H
#define manager_H
#include "item.h"
#include <list>
#include <iostream> 
using namespace std;

class Manager : public Item {

    enum State {office = 0, visit = 1};
    State state;

    public:

    //overiding Item function "run()"
    void Run();

    //returns the state of the manager
    void  getManagerState();














};
#endif
