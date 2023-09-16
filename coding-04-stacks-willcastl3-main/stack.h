/*********************
Name: William Castillo
Coding 04
Purpose: To create a stack object that will work with a struct data type.
**********************/


#ifndef STACK_H
#define STACK_H

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:
    Stack();
    bool push(int, const string*);
    bool pop(Data&);
    bool peek(Data&);
    bool isEmpty();
    void dumpStack();
private:


    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H