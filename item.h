//item.h
//Amy Vinson and Brady O'Leary
//

#ifndef ITEM_H
#define ITEM_H

class item {
    public:
        int key;
        virtual void Run();
        item():key(0);//default item constructor that sets key to zero
};

struct compareItem : binary_function<Item*, Item*, bool> {
    bool operator()(const Item* t1, const Item* t2) const {
        return (t1->key > t2->key);
    }
}

#endif
