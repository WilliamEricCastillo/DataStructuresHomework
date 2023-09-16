/*********************
Name: William Castillo
Coding 06
Purpose: To create a Hash Table class/object with our
standard struct.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "\nShowing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    
    Hashtable hashtable;

    // show it is empty by calling getCount and printTable
    cout << "********* TEST CASE: EMTPY LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;


    
    cout << "********* TEST CASE: PRINT EMTPY LIST *********" << endl;
    hashtable.printTable();
    cout << endl;

    // try and put ALL the test data into the table and show what happens
    cout << "********* TEST CASE: FILLING LIST WITH TEST DATA *********" << endl;
    cout << "Inserting Test Data (" << testdatasize << " entries)..." << endl;

    for (int i = 0; i < testdatasize; i++){
        if(hashtable.insertEntry(ids[i], strs[i])){
            cout << "Success " << ids[i] << " : " << strs[i] << endl;
        }else
        {
            cout << "Failed " << ids[i] << " : " << strs[i] << endl;
        };
    }
    cout << "List is filled..." << endl << endl;

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
    
    
    
    cout << "********* TEST CASE: FILLED LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;



    cout << "********* TEST CASE: PRINT FILLED LIST *********" << endl;
    hashtable.printTable();
    cout << endl;



    cout << "********* TEST CASE: GET DATA *********" << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Getting " << ids[i]<< ":" << hashtable.getData(ids[i]) << endl;
    }
    cout << endl;



    cout << "********* TEST CASE: REMOVE DATA FIRST, MIDDLE, LAST IDs & NULL ID *********" << endl;
    cout << "Deleting Test Data..." << endl;

    cout << "Trying: " << ids[0] << "..." << endl;
    if(hashtable.removeEntry(ids[0])) {
        cout << "  Success: " << ids[0] << " removed" << endl;
    } else {
        cout << "  Failed " << ids[0] << " was not removed" << endl;
    }

    cout << "Trying: " <<    ids[(int) (testdatasize - 1) / 2] << "..." << endl;
    if(hashtable.removeEntry( ids[(int) (testdatasize - 1) / 2])) {
        cout << "  Success: " << ids[(int) (testdatasize - 1) / 2]  << " removed" << endl;
    } else {
        cout << "  Failed " << ids[(int) (testdatasize - 1) / 2]  << " was not removed" << endl;
    }

    cout << "Trying: " << ids[testdatasize - 1] << "..." << endl;
    if (hashtable.removeEntry(ids[testdatasize - 1])) {
        cout << "  Success: " << ids[testdatasize - 1] << " removed" << endl;
    } else {
        cout << "  Failed " << ids[testdatasize - 1] << " was not removed" << endl;
    }

    cout << "Trying: " << MAXID + 1 << "..." << endl;
    if (hashtable.removeEntry(MAXID + 1)) {
        cout << "  Success: " << MAXID + 1 << " removed" << endl;
    } else {
        cout << "  Failed " << MAXID + 1 << " was not removed" << endl;
    }

    cout << endl;




    cout << "********* TEST CASE: FILLED LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;



    cout << "********* TEST CASE: PRINT LIST AFTER REMOVE DATA *********" << endl;
    hashtable.printTable();
    cout << endl;


    cout << "********* TEST CASE: DELETING ALL DATA && PRINT EMTPY LIST *********" << endl;
    cout<< "Deleting data..." << endl;
    hashtable.clearList();
    cout<< "Deleting data complete..." << endl << endl;
    cout<< "Printing list ..." << endl;
    hashtable.printTable();
    cout<< "Printing list complete ..." << endl << endl;



    cout << "********* TEST CASE: FILLED LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;



    cout << "********* TEST CASE: FILLING LIST WITH TEST DATA TWICE *********" << endl;
    cout << "Inserting Test Data (" << testdatasize << " entries)..." << endl;

    for (int i = 0; i < testdatasize; i++){
        if(hashtable.insertEntry(ids[i], strs[i])){
            cout << "Success " << ids[i] << " : " << strs[i] << endl;
        }else
        {
            cout << "Failed " << ids[i] << " : " << strs[i] << endl;
        };
    }
    cout << "List is filled..." << endl << endl;

    cout << "Filling Second Time..." << endl;
    for (int i = 0; i < testdatasize; i++){
        if(hashtable.insertEntry(ids[i], strs[i])){
            cout << "Success " << ids[i] << " : " << strs[i] << endl;
        }else
        {
            cout << "Failed " << ids[i] << " : " << strs[i] << endl;
        };
    }
    cout << "List is filled..." << endl << endl;


    cout << "********* TEST CASE: FILLED LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;



    cout << "********* TEST CASE: PRINT FILLED LIST *********" << endl;
    hashtable.printTable();
    cout << endl;



    cout << "********* TEST CASE: DELETING ALL DATA && PRINT EMTPY LIST *********" << endl;
    cout<< "Deleting data..." << endl;
    hashtable.clearList();
    cout<< "Deleting data complete..." << endl << endl;
    cout<< "Printing list ..." << endl;
    hashtable.printTable();
    cout<< "Printing list complete ..." << endl << endl;


    cout << "********* TEST CASE: FILLED LIST COUNT *********" << endl;
    cout << "Hashtable count: " << hashtable.getCount() << endl << endl;


    return 0;
}
