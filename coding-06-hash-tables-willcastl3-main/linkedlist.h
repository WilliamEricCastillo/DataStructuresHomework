/*********************
Name: William Castillo
Coding 06
Purpose: To create a Hash Table class/object with our
standard struct.
**********************/

#include "data.h"

#include <iostream>

using std::cout;
using std::endl;

class LinkedList{

public:

    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    Node *head;
    void addHead(int&, string*);
    void replaceHead(int&, string*);
    void replaceTail(int&, string*, Node*);
    void addMiddle(int&, string*, Node*);
    Node* newNode(int&, string*, Node*);
    void printListBackward();
    void printListForward();
};
