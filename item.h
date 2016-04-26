//item.h
//Amy Vinson and Brady O'Leary
//

#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

#include <queue>
#include<vector>
#include<stdlib.h>
using namespace std;
class Item{
    int key;
    public:
    Item() : key(0) {}
    int getKey() {return key;}
    void setKey(int a) {key = a;}
    Item(int k) : key (k) {}
    friend class compareItem;
    virtual void Run() {}
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

