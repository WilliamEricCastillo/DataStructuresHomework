/*********************
Name: William Castillo
Coding 03
Purpose: To introduce a simple ADT (abstract data type) and understand the function and purpose of
ADTs.
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define SIZE_OF_STACK 10
#define TOP_MIN (-1)

class Stack{

public:
    // declaring all the function
    Stack();
    bool push(int);
    int pop();
    bool isEmpty();
    int peek();

private:
    int top;
    int int_stack[SIZE_OF_STACK];
};

#endif //STACK_STACK_H