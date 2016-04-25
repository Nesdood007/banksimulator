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

class item {
    public:
	item():key(0){}//default item constructor that sets key to zero
	int getKey(){ 
		return key;
	}
	int setKey(int a) {
		key = a;
	}
	item(int k) : key(k){}
	friend class compareItem;
	virtual void Run(){}
	virtual ~item(){}
};

struct compareItem : binary_function<Item*, Item*, bool> {
    bool operator()(const Item* t1, const Item* t2) const {
        return (t1->key > t2->key);
    }
}

#endif
