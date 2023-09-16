/*********************
Name: William Castillo
Coding 02
Purpose: This is a simple application to demonstrate classes and objects in C++.
**********************/

#include "circle.h"

Circle::Circle(){
    setRadius(MIN);
}

Circle::Circle(double r){
    setRadius(r);

}

double Circle::getRadius() {
    return radius;
}

double Circle::getCircumference() {
    return 2 * M_PI * radius;
}

double Circle::getArea() {

    return M_PI * pow(radius,2.0);
}

void Circle::setRadius(double r) {
    if(r > MIN){
        radius = r;
    } else{
        radius = MIN;
    }
}

Circle::~Circle() {
}
