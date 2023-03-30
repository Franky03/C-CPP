#pragma once
#include "Shape.h"
#include <iostream>

class Circle: public Shape {
    private:
        double radius;
        static const double pi = 3.14;
    public:
        Circle();
        Circle(radius:double);
        Circle(radius:double, color:std::string, filled:bool);
        double getRadius();
        void setRadius(radius:double);

        double getArea();
        double getPerimeter();
        std::string toString();
};
