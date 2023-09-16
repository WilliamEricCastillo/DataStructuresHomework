/*********************
Name: William Castillo
Coding 06
Purpose: To create a Hash Table class/object with our
standard struct.
**********************/
#include "hashtable.h"

Hashtable::Hashtable() {
    count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = nullptr;
    }
}

int Hashtable::getCount() {
    return count;
}

void Hashtable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){

        if(hashtable[i] != NULL){
            cout << "Entry " << i << ": ";
            hashtable[i]->printList();
        }else{
            cout << "Entry " << i << ": EMPTY" ;
            cout << endl ;
        }
    }
}

int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}

bool Hashtable::insertEntry(int id, string data){
    bool inserted;
    int position = hash(id);

    if(hashtable[position]){
        inserted = hashtable[position]->addNode(id, &data);

    }else{
        LinkedList *list = new LinkedList;
        inserted = list->addNode(id, &data);

        if(inserted){
            hashtable[position] = list;
        }else{
            delete list;
        }
    }

    if(inserted){
        count++;
    }

    return inserted;
}

string Hashtable::getData(int id) {
    int position = hash(id);
    Data data;
    data.data = "";

    if(position > -1){
        hashtable[position]->getNode(id, &data);
    }
    return data.data;
}

bool Hashtable::removeEntry(int id) {
    bool status = false;
    int position = hash(id);

    if (position > -1  && hashtable[position]) {

         if(hashtable[position]->exists(id)){
             hashtable[position]->deleteNode(id);
             status = true;
         }

         if (hashtable[position]->getCount() == 0) {
            hashtable[position] = NULL;
        }

    }else if (hashtable[position] == NULL){
        status = false;
    }
    return status;
}

void Hashtable::clearList(){
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if(hashtable[i]!= NULL){
            hashtable[i]->clearList();
            hashtable[i] = NULL;
        }
    }
    count = 0;
}

Hashtable::~Hashtable() {
    clearList();
}

