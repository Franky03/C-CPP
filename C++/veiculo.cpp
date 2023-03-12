#include "veiculo.h"
#ifndef VEICULO_H
#define VEICULO_H


Veiculo::Veiculo()
{
}

void Veiculo::xlr8(double increase)
{
    velocity += increase;
}
void Veiculo::stop(double decrease)
{
    velocity -= decrease;
}
void Veiculo::getVelocity()
{
    return velocity;
}
