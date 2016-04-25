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

    priority_queue<item*, vector<item*>, compareItem> pq;
    srand(time(0));
    item* item;
    bank bank(10, 5, 1, pq);
    while(!pq.empty()) {
        item = pq.top();
        cout << item -> getKey() << endl;
        item -> run();
        pq.pop();
    }
    //give report of bank stats.
    return 0;
}, 
