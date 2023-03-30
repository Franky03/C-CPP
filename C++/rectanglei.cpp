#pragma once
#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
    setWidth(0);
    setLength(0);
}

Rectangle::Rectangle(width:double, width:double) : Shape()
{
    setWidth(width);
    setLength(length);
}

Rectangle::Rectangle(width:double, width:double, color:std::string, filled:bool) 
: Shape(color, filled)
{
    setWidth(width);
    setLength(length);
}

double Rectangle::getWidth(){
    return this->width;
}

void Rectangle::setWidth(width:double){
    this->width = width;
}

double Rectangle::getLength(){
    return this->length;
}
void Rectangle::setLength(length:double){
    this->length = length;
}

double Rectangle::getArea() {
    return width*length;
}

double Rectangle::getPerimeter(){
    return 2*(width+length);
}

std::string Rectangle::toString(){
    return "A Rectangle with " + std::to_string(getWidth()) 
    + "of width, " + std::to_string(getLength()) + "of length "+"and color " 
    + getColor() + "is filled: " + (isFilled ? "true" : "false");
}

