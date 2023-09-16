/*********************
Name: William Castillo
Coding 05
Purpose: : To create a fully functional doubly linked list class,
a linked list object from class and
demonstrate complete testing and full functionality of linked list.
**********************/

#include "data.h"
#include "iostream"

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
