/*********************
Name: William Castillo
Coding 04
Purpose: To create a stack object that will work with a struct data type.
**********************/

// each cpp includes ONLY it's header directly!
#include "stack.h"
#include "iostream"


Stack::Stack() {
    this->top = -1;
}

bool Stack::push(int x, const string *userString) {
    bool status = false;

    if(top < STACK_SIZE - 1 && x > 0 && userString->length() > 0){
        Data *myDataArray = new Data;
        myDataArray->id = x;
        myDataArray->information = *userString;
        stack[++top] = myDataArray;
        status = true;
    }

    return status;
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::pop(Data &userStruct) {

    bool status = true ;

    if(isEmpty()){
        userStruct.id = -1;
        userStruct.information = "";
        status = false;

    } else{
        userStruct.id = stack[top]->id;
        userStruct.information = stack[top]->information;
        delete stack[top--];
    }

    return status;
}

bool Stack::peek(Data &userStruct) {
    bool status = true ;

    if(isEmpty()){
        userStruct.id = -1;
        userStruct.information = "";
        status = false;

    } else{
        userStruct.id = stack[top]->id;
        userStruct.information = stack[top]->information;
    }

    return status;
}

void Stack::dumpStack() {
    std::cout << "dumping whole stack..." << std::endl;
    if (!isEmpty()) {
        for (int i = top; i >= 0; i--) {
            std::cout << "ID: "<< stack[i]->id << std::endl;
            std::cout << "Information: " << stack[i]->information << std::endl;
        }
    } else {
        std::cout << "\tstack is empty" << std::endl;
    }
    std::cout << std::endl;
}