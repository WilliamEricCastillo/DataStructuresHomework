/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#include "sphere.h"

Sphere::Sphere(){
    setRadius(MIN);
    setCapHeight(MIN);
}

Sphere::Sphere(double r, double ch) {
    setRadius(r);
    setCapHeight(ch);
}

double Sphere::getArea() {
    return (4 * M_PI * pow(radius,2.0));
}

double Sphere::getVolume() {
    return pow(radius, 3.0) * M_PI * 4/3;
}

double Sphere::getCapHeight() {
    return capHeight;
}

double Sphere::getCapVolume()
{return (((pow(capHeight,2.0) * radius) - ((pow(capHeight,3.0)/3))) * M_PI);
}

void Sphere::setCapHeight(double ch)
{
    if(ch > MIN && ch < radius)
    {
        capHeight = ch;
    }else{
        capHeight = MIN;
    }
}

Sphere::~Sphere() {
}
