//item.h
//Amy Vinson and Brady O'Leary
//

#ifndef ITEM_H
#define ITEM_H
#include <iostream>

#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;
class Item{
    int key;
    public:
    Item() : key(0) {}
    Item(const int& a) {key = a;}
    int getKey() {return key;}
    void setKey(const int& a) {key = a;}
    Item(int k) : key(k) {}
    friend class compareItem;
    virtual void run() {cout << "Ran Item. NOT OK" << endl;}
    virtual ~Item(){}
};

struct compareItem
: binary_function<Item*, Item*, bool>
{
    bool operator()(const Item* t1, const Item* t2) const
    {
        return (t1->key > t2->key);
    }
};

 
#endif

