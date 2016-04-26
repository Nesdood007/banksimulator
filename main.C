//main file for Project 7
//Amy Vinson, Brady O'Leary
//CSCE 240, Spring 2016

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include "bank.h"
#include "item.h"
#include "manager.h"
#include "teller.h"
#include "customer.h"
using namespace std;

int main() {

    priority_queue<Item*, vector<Item*>, compareItem> pq;
    srand(time(0));
    Item* Item;
    Bank Bank(10, 5, 1, pq);
    while(!pq.empty()) {
        Item = pq.top();
        cout << item -> getKey() << endl;
        item -> run();
        pq.pop();
    }
    //give report of bank stats.
    return 0;
} 
