/*********************
Name: William Castillo
Coding 03
Purpose: To introduce a simple ADT (abstract data type) and understand the function and purpose of
ADTs.
**********************/

#include "stack.h"

Stack::Stack(){
    top = TOP_MIN;
}

bool Stack::push(int push_value){
    bool status = false;

    if(top != SIZE_OF_STACK - 1 ){
        int_stack[++top] = push_value;
         status = true;
    }
    
    return status;
}

bool Stack::isEmpty(){
    return top < 0;
}

int Stack::pop(){

    if(isEmpty()){
        throw (2);
    }

    return int_stack[top--];
}

int Stack::peek(){

    if(isEmpty()){
        throw (2);
    }

    return int_stack[top]; // correct code
}
