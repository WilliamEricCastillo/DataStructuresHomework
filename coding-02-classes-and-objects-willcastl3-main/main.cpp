/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#include "main.h"

int main(int argc, char** argv){

    Circle myCircle1;

    Circle myCircle2(4);

    Sphere mySphere1;
    Sphere mySphere2(6, 2);

    displayCircle(&myCircle1);
    displayCircle(&myCircle2);

    displaySphere(&mySphere1);
    displaySphere(&mySphere2);

    return 0;
}