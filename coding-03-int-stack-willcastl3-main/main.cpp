/*********************
Name: William Castillo
Coding 03
Purpose: To introduce a simple ADT (abstract data type) and understand the function and purpose of
ADTs.
**********************/

#include "main.h"

int main(int argc, char** argv) {

    Stack s1;

    cout << endl;
    cout << "*TEST*: Checks if stack is empty*" << endl;
    if(s1.isEmpty()){
        cout << "Stack = empty" << endl;
    }else{
        cout<< "Stack = not empty" << endl;
    }
    cout << endl;

    cout << "*TEST*: PUSH while stack is empty*" << endl;
    for(int i = 0; i < 10; ++i){
        if(s1.push(i)){
            cout << "Push Value "<< i << " = success" << endl;
        }else{
            cout << "Push Value "<< i << " = failure" << endl;
        }
    }
    cout << endl;

    cout << "*TEST*: Checks if stack is empty*" << endl;
    if(s1.isEmpty()){
        cout << "Stack = empty" << endl;
    }else{
        cout<< "Stack = not empty" << endl;
    }
    cout << endl;

    cout << "*TEST: PEEK while stack is full" << endl;
    for(int i = 0; i < 10; ++i){
        try{
            cout << "Peek Value = "<< s1.peek() << endl;
        }catch(int under_flow){
            cout << "Error: Underflow" << endl;
        }
    }
    cout << endl;

    cout << "*TEST*: PEEK after POP while stack is full" << endl;
    for(int i = 9; i > -1  ; --i) {
        try{
            cout << "Peek Value = " << s1.peek() << endl;
            cout << "Pop element [" << i <<"] Value = "<< s1.pop() << endl;
        }catch(int under_flow){
            cout << "Error: Underflow" << endl;
        }
    }
    cout << endl;

    cout << "*TEST: POP while stack is empty" << endl;
    for(int i = 0; i < 10; ++i){
        try{
            cout << "Pop value = "<< s1.pop() << endl;
        }catch (int under_flow){
            cout << "Error: Underflow" << endl;
        }
    }

    cout << endl;

    cout << "*TEST: PEEK while stack is empty" << endl;
    for(int i = 0; i < 10; ++i) {
        try {
            cout << "Peek Value = "<< s1.peek() << endl;
        } catch (int under_flow) {
            cout << "Error: Underflow" << endl;
        }
    }

    cout << endl;
    cout << "*TEST*: PUSH to stack past overflow*" << endl;
    for(int i = 0; i < 16; ++i){
        if(s1.push(i)){
            cout << "Push Value "<< i << " = success" << endl;
        }else{
            cout << "Push Value "<< i << " = failure" << endl;
        }
    }

    cout << endl;
    cout << "*Test*: POP past underflow*" << endl;
    for(int i = 9; i > -6  ; --i){
        try {
            cout << "Popping element [" << i << "] Value = "<< s1.pop() << endl;
        }catch (int under_flow){
            cout << "Error: Underflow" << endl;
        }
    }

    cout << endl;
    cout << "*TEST*: PEEK after PUSH past overflow*" << endl;
    for(int i = 0; i < 16; ++i){
        try {
            if(s1.push(i)){
                cout << "Push Value "<< i << " = success" << endl;
                cout << "Peek Value = "<< s1.peek() << endl;
            }
        }catch(int over_flow){
            cout << "Error: Push " << i << " causes overflow" << endl;
        }
    }

    cout << endl;
    cout << "*Test: Peek after POP past underflow*"<< endl;
    for(int i = 9; i > -6  ; --i) {
        try {
            cout << "Peek Value = "<< s1.peek() << endl;
            cout << "Popping element [" << i <<"] Value = "<< s1.pop() << endl;
        } catch (int under_flow) {
            cout << "Error: Underflow" << endl;
        }
    }

    cout << endl;
    cout << "*TEST: PUSH to stack midway*" << endl;
    for(int i = 0; i < 5; ++i){
        if(s1.push(i)){
            cout << "Push Value "<< i << " = success" << endl;
        }else{
            cout << "Push Value "<< i << " = failure" << endl;
        }
    }

    cout << endl;
    cout << "*TEST: PUSH from stack midway past overflow*" << endl;
    for(int i = 5; i < 15; ++i){
        if(s1.push(i)){
            cout << "Push Value "<< i << " = success" << endl;
        }else{
            cout << "Push Value "<< i << " = failure" << endl;
        }
    }

    cout << endl;
    cout << "*TEST: POP from full stack to mid stack*" << endl;
    for(int i = 9; i > 4  ; --i) {
        try {
            cout << "Pop element [" << i <<"] Value = "<< s1.pop() << endl;
        } catch (int under_flow) {
            cout << "Error: Underflow" << endl;
        }
    }

    cout << endl;
    cout << "*TEST: POP from mid stack past underflow*" << endl;
    for(int i = 4; i > -6  ; --i) {
        try {
            cout << "Pop element [" << i <<"] Value = "<< s1.pop() << endl;
        } catch (int under_flow) {
            cout << "Error: Underflow" << endl;
        }
    }
    cout << endl;

    srand((unsigned) time(0));
    int randomNumber1;
    int randomNumber2;
    int randomNumber3;

    cout << "*TEST: Pushing,Popping,Peaking randomly over 200 iterations.*" << endl;
    for(int i = 0; i < 200; ++i){
        randomNumber1 = (rand() % 1000) + 1;
        randomNumber2 = (rand() % 1000) + 1;
        randomNumber3 = (rand() % 1000) + 1;

        if(randomNumber3 > randomNumber1){
            if(s1.push(i)){
                cout << "Push Value "<< i << " = success" << endl;
            }else{
                cout << "Push Value "<< i << " = failure" << endl;
            }
        }

        if(randomNumber2 > randomNumber1){
            try {
                cout << "Peek Value = "<< s1.peek() << endl;
            }catch(int under_flow){
                cout << "Error: Underflow" << endl;
            }
        }

        if(randomNumber1 > randomNumber3){
            try {
                cout << "Popping Value = "<< s1.pop() << endl;
            }catch(int under_flow){
                cout << "Error: Underflow" << endl;
            }
        }

        if(randomNumber3 < randomNumber2){
            if(s1.isEmpty()){
                cout << "Stack is empty" << endl;
            }else{
                cout<< "Stack is not empty" << endl;
            }
        }
    }

    return 0;

};