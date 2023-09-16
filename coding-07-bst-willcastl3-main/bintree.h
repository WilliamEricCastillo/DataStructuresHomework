/*********************
Name: William Castillo
Coding 07
Purpose: To create a create a Binary Search Tree object that will work with
the same struct Data and struct Node from the previous assignments.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree{
    
public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    DataNode *root;
    int count;
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    DataNode* minValueNode(DataNode*);
};


#endif /* BINTREE_BINTREE_H */

