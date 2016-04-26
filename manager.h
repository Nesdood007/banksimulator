//manager.h
//Brady O'Leary and Amy Vinson

#ifndef manager_H
#define manager_H
#include "item.h"
#include <list>
#include <iostream> 
using namespace std;

class Manager : public Item {

    enum state {office = 0, visit = 1};

    public:

    //overiding Item function "run()"
    void Run();
















};
#endif
