/*********************
Name: William Castillo
Coding 06
Purpose: To create a Hash Table class/object with our
standard struct.
**********************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "linkedlist.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:

    Hashtable();
    ~Hashtable();
    bool insertEntry(int, string);
    int getCount();
    void printTable();
    string getData(int);
    bool removeEntry(int);
    void clearList();

private:

    int hash(int);
    LinkedList *hashtable[HASHTABLESIZE];
    int count;

};

#endif /* HASHTABLE_HASHTABLE_H */
