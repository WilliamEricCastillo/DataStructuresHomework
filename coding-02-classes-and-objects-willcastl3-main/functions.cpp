/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#include "functions.h"

void displayCircle(Circle *myCircle){

    cout << myCircle->getRadius() << endl;
    cout << myCircle->getCircumference() << endl;
    cout << myCircle->getArea() << endl;
    cout << endl;
}


void displaySphere(Sphere *mySphere){

    cout << mySphere->getRadius() << endl;
    cout << mySphere->getCircumference() << endl;
    cout << mySphere->getArea() << endl;
    cout << mySphere->getVolume() << endl;
    cout << mySphere->getCapHeight() <<endl;
    cout << mySphere->getCapVolume() <<endl;
    cout << endl;
}