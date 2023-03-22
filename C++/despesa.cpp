#include "despesa.h"
#include <iostream>

using namespace std;

Despesa::Despesa()
{
}

void Despesa::setNome(string name)
{
    nome = name;
}

void Despesa::setValor(float val)
{
    valor = val;
}

void Despesa::setTipo(string type)
{
    tipoGasto = type;
}

float Despesa::getValor()
{
    return valor;
}

string Despesa::getTipoGasto()
{
    return tipoGasto;
}

string Despesa::getNome()
{
    return nome;
}
