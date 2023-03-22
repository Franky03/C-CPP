#include "controlegasto.h"
#include <iostream>

using namespace std;

ControleDeGastos::ControleDeGastos()
{
    
}

void ControleDeGastos::setDespesa(Despesa d, int pos)
{
    despesa[pos] = d;
}

Despesa ControleDeGastos::getDespesa(int pos)
{
    return despesa[pos];
}

float ControleDeGastos::calculaTotalDespesa()
{
    float total=0;
    for(Despesa desp : despesa){
        total += desp.getValor(); 
    }
    return total;
}

float ControleDeGastos::calculaTotalDespesa(string tipo)
{
    float total=0;
    for(Despesa desp : despesa) {
        if(desp.getTipoGasto() == tipo){
            total += desp.getValor();
        }
    }
    return total;
}

bool ControleDeGastos::existeDespesaDoTipo(string tipo)
{
    for(Despesa desp: despesa){
        if(desp.getTipoGasto() == tipo)
            return true;
    }
    return false;
}

