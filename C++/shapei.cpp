#include "Shape.h"
#include <iostream>

Shape::Shape()
{
    setColor("");
    setFilled(false);
}

Shape::Shape(color: std::string, filled:bool)
{
    setColor(color);
    setFilled(filled);
}

std::string Shape::getColor(){
    return this->color;
}

void Shape::setColor(color:std::string){
    this->color = color;
}

bool Shape::isFilled(){
    return this->filled;
}

void Shape::setFilled(filled:bool){
    this->filled = filled;
}

