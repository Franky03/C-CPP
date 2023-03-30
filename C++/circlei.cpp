#include "Circle.h"
#include <iomanip>

Circle::Circle() : Shape()
{
    setRadius(0);
}

Circle::Circle(radius:double) : Shape()
{
    setRadius(radius);
}

Circle::Circle(radius:double, color:std::string, filled:bool) 
: Shape(color, filled)
{
    setRadius(radius);
}

double Circle::getRadius(){
    return this->radius;
}

void Circle::setRadius(radius:double){
    this->radius = radius;
}

double Circle::getArea() {
    return raio*raio*pi;
}

double Circle::getPerimeter(){
    return 2*pi*radius;
}

std::string Circle::toString(){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(3) << pi;

    return "A Circle with " + stream.str() + "of radius and color " + getColor() + "is filled: " + (isFilled ? "true" : "false");
}




