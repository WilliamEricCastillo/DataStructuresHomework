/*********************
Name: William Castillo
Coding 07
Purpose: To create a create a Binary Search Tree object that will work with
the same struct Data and struct Node from the previous assignments.
**********************/

#include "bintree.h"

// public methods
BinTree::BinTree() {
    root = nullptr;
    count = 0;
}

BinTree::~BinTree() {
    clear();
}

bool BinTree::isEmpty() {
    return root;
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data *userData) {
    bool status = false;

    if(root != nullptr){
        userData->id = root->data.id;
        userData->information = root->data.information;
        status = true;

    }else{
        userData->id = -1;
        userData->information = "";
    }

    return status;
}

bool BinTree::addNode(int id, const string *information) {
    bool status = false;

    if(id > 0 && information->length() > 0) {
        DataNode *newNode = new DataNode;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data.id = id;
        newNode->data.information = *information;

        if (addNode(newNode, &root)) {
            count++;
            status = true;
        }
    }

    return status;
}

bool BinTree::removeNode(int id) {
    int tempcount = count;

    root = removeNode(id, root);

    return (count < tempcount);
}

bool BinTree::getNode(Data *userData, int id) {
    bool status = false;

    if(id > 0){
        status = getNode(userData, id, root);
    }

    return status;
}

bool BinTree::contains(int id) {
    bool status = false;

    if(id > 0){
        status = contains(id, root);
    }

    return status;
}

int BinTree::getHeight() {
    return getHeight(root);
}

void BinTree::displayTree() {

    if(isEmpty()){
        cout << "Tree is NOT empty" << endl;
    }else{
        cout << "Tree is empty" << endl;
    }

    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << endl;

    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;

    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;

    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << endl;
}

void BinTree::clear() {
    clear(root);
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}

//private methods
void BinTree::displayPreOrder(DataNode *temproot) {

    if (temproot) {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        displayPreOrder(temproot->left);
        displayPreOrder(temproot->right);
    }

    return;
}

void BinTree::displayPostOrder(DataNode *temproot) {

    if (temproot) {
        displayPostOrder(temproot->left);
        displayPostOrder(temproot->right);
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }

    return;
}

void BinTree::displayInOrder(DataNode *temproot) {

    if (temproot) {
        displayInOrder(temproot->left);
        cout << temproot->data.id << " " << temproot->data.information << endl;
        displayInOrder(temproot->right);
    }

    return;
}

bool BinTree::addNode(DataNode *newNode, DataNode **temproot) {
    bool status = true;

    if((*temproot)){

        if(newNode->data.id < (*temproot)->data.id){
            status = addNode(newNode, &((*temproot)->left));

        }else if(newNode->data.id > (*temproot)->data.id){
            status = addNode(newNode, &((*temproot)->right));
        }

    }else{
        *temproot = newNode;
    }

    return status;
}

bool BinTree::contains(int id, DataNode *temproot) {
    bool status = false;

    if(temproot){
        if(temproot->data.id != id){

            if(id < temproot->data.id){
                status = contains(id, temproot->left);
            }else{
                status = contains(id, temproot->right);
            }

        }else if(temproot->data.id == id){
            status = true;
        }
    }

    return status;
}

bool BinTree::getNode(Data *userData, int id, DataNode *temproot) {
    bool status = false;

    if(temproot){
        if(temproot->data.id != id){

            if(id < temproot->data.id){
                status = getNode(userData, id, temproot->left);
            }else{
                status = getNode(userData, id, temproot->right);
            }

        }else if(temproot->data.id == id){
            userData->id = temproot->data.id;
            userData->information = temproot->data.information;
            status = true;
        }
    }

    return status;
}

int BinTree::getHeight(DataNode *temproot) {
    int height = 0;
    int lh = 0;
    int rh = 0;

    if (temproot){
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        height = std::max(lh, rh) + 1;
        }

    return height;
}

void BinTree::clear(DataNode *temproot) {

    if(temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = nullptr;
        temproot->right = nullptr;
        delete temproot;
        count--;
        root = nullptr;

    }
}

DataNode *BinTree::removeNode(int id, DataNode *temproot) {

    if(temproot){
        if(id < temproot->data.id){
            temproot->left = removeNode(id, temproot->left);

        }else if(id > temproot->data.id){
            temproot->right = removeNode(id, temproot->right);

        }else if (id == temproot->data.id){
            DataNode *temp;

            if(temproot->left == nullptr){
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;

            }else if(temproot->right == nullptr){
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;

            }else if(temproot->left && temproot->right){
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }

    return temproot;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}
