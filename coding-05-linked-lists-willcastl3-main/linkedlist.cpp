/*********************
Name: William Castillo
Coding 05
Purpose: : To create a fully functional doubly linked list class,
a linked list object from class and
demonstrate complete testing and full functionality of linked list.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string *stringData) {
    bool status = true;

    if (id > 0 && stringData->length() > 0){
        Node *current = head;
        Node *duplicate = head;

        if (current != NULL) {
            while(duplicate->data.id != id && duplicate->next){
                duplicate = duplicate->next;
            }
            if(id != duplicate->data.id){
                if (id > current->data.id){
                    while(id > current->data.id && current->next != NULL){
                        current = current->next;
                    }
                    if (current->data.id < id && current->next == NULL) {
                        replaceTail(id,stringData,current);
                    } else {
                        addMiddle(id,stringData,current);
                    }
                } else{
                    replaceHead(id,stringData);
                }
            }else{
                status = false;
            }
        }else{
            addHead(id, stringData);
        }
    }else{
        status = false;
    }
    return status;
}

bool LinkedList::deleteNode(int id) {
    bool status = true;
    Node *current = head;

    while (current->data.id != id && current->next) {
        current = current->next;
    }

    if(id == current->data.id && current)
    {
        if (current->prev && current->next) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;

        }else if( current->next == NULL && current->prev && current->prev->prev) {

            current->prev->prev->next = current->prev;
            current->prev->next = NULL;
            delete current;

        }else if (current->prev == NULL && current->next && current->next->next) {

            current->next->next->prev = current->next;
            current->next->prev = NULL;
            head = current->next;
            delete current;

        } else if( current->prev == NULL && current->next && current->next->next == NULL){
            current->next->prev = NULL;
            current->next->next = NULL;
            head = current->next;
            delete current;

        } else if(current->next == NULL && current->prev && current->prev->prev == NULL){
            current->prev->next = NULL;
            delete current;
        }
    } else {
        status = false;
    }

    return status;
}

bool LinkedList::getNode(int id, Data *data) {
    bool status = true;
    Node *current = head;

    while(current->data.id != id && current->next!= NULL ){
        current = current->next;
    }

    if (id == current->data.id){
        data->id = current->data.id;
        data->data = current->data.data;
    }else{
        status = false;
    }

    return status;
}

void LinkedList::printList(bool backwards) {
    if(!backwards){
        printListForward();
    }else{
        printListBackward();
    }
}

int LinkedList::getCount(){

    Node *current = head;

    int count = 0;
    while(current) {
        current = current->next;
        count++;
    }

    return count;
}

bool LinkedList::clearList() {
    bool status = true;
    Node *current = head;

    if(current){
        while(current){
            Node *trash = current;
            current = current->next;
            delete trash;
        }
        head = NULL;

    } else{
        status = false;
    }

    return status;
}

bool LinkedList::exists(int id) {

    bool status = false;
    Node *current = head;

    while(current->data.id != id && current->next!= NULL ){
        current = current->next;
    }

    if (id == current->data.id) {
        status = true;
    }

    return status;

}

void LinkedList::printListForward() {
    Node* current = head;
    while(current){
        cout << current->data.id << ": " << current->data.data << endl;
        current = current->next;
    }
}

void LinkedList::printListBackward() {
    Node *current = head;
    while(current->next) {
        current = current->next;
    }
    while(current){
        cout << current->data.id << ": " << current->data.data << endl;
        current = current->prev;
    }
}

void LinkedList::addHead( int &id, string *stringData){
    Node *addHead = newNode(id,stringData, addHead);
    addHead->next = NULL;
    addHead->prev = NULL;
    head = addHead;
}

void LinkedList::replaceHead(int &id , string *stringData) {

    Node *replaceHead = newNode(id,stringData, replaceHead);
    head->prev = replaceHead;
    replaceHead->next = head;
    replaceHead->prev = NULL;
    head = replaceHead;

}

void LinkedList::replaceTail(int &id, string *stringData, Node *current) {

    Node *replaceTail = newNode(id,stringData, replaceTail);
    replaceTail->next = NULL;
    replaceTail->prev = current;
    current->next = replaceTail;
}

void LinkedList::addMiddle(int &id, string *stringData, Node *current) {
    Node *addMiddle = newNode(id,stringData, addMiddle);
    addMiddle->next = current;
    addMiddle->prev = current->prev;
    current->prev->next = addMiddle;
    current->prev = addMiddle;
}

Node* LinkedList::newNode(int &id, string *stringDada, Node *newNode) {
    newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *stringDada;
    return newNode;
}

