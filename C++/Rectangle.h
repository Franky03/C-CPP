#pragma once
#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
    double width;
    double length;

    public:
        Rectangle();
        Rectangle(width:double, width:double);
        Rectangle(width:double, width:double, color:std::string, filled:bool);
        double getWidth();
        void setWidth(width:double);
        double getLength();
        void setLength(length:double);

        double getArea();
        double getPerimeter();
        std::string toString();
};

