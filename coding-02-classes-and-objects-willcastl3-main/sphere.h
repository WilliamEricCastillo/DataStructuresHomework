/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere : public Circle{

public:
    Sphere();
    Sphere(double, double);
    ~Sphere();

    double getVolume();
    double getCapHeight();
    double getCapVolume();
    double getArea();

    void setCapHeight(double);

private:
    double capHeight;
};

#endif //CLASSES_SPHERE_H