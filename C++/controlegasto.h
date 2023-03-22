#include "despesa.h"
#include <iostream>

using namespace std;

class ControleDeGastos 
{
    private:
        Despesa despesa[100];
    public:
        ControleDeGastos();
        void setDespesa(Despesa d, int pos);
        Despesa getDespesa(int pos);
        float calculaTotalDespesa();
        float calculaTotalDespesa(string tipo);
        bool existeDespesaDoTipo(string tipo);

};