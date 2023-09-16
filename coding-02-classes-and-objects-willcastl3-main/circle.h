/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#include <cmath>

#define MIN 0

class Circle {

public:
    Circle();
    Circle(double);
    ~Circle();

    double getRadius();
    double getCircumference();

    double getArea();

    void setRadius(double);


protected:
    double radius;


};

#endif //CLASSES_CIRCLE_H


