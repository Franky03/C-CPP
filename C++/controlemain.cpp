#include <iostream>
#include "controlegasto.h"
using namespace std;

int main(void){
    int N;
    float valor;
    string nome, tipo;

    Despesa d;
    ControleDeGastos cdg;

    cin >> N;
    cin.ignore();

    for(int i=0; i<N; i++){
        getline(cin, nome);
        cin >> valor;
        cin.ignore();
        getline(cin, tipo);
        
        d.setNome(nome);
        d.setTipo(tipo);
        d.setValor(valor);

        cdg.setDespesa(d, i);
    }

    cin>> tipo;
    if(cdg.existeDespesaDoTipo(tipo)){
        for(auto i=0; i<100; i++){
            d = cdg.getDespesa(i);
            if(d.getTipoGasto() == tipo){
                cout << d.getNome() << ", R$ "<< d.getValor() << endl;
            }
        }
    }
    else 
    {
        cout << "Nenhuma despesa do tipo especificado" << endl;
    }

    cout<< "Total: " << cdg.calculaTotalDespesa(tipo) << "/" << cdg.calculaTotalDespesa() << endl;

    return 0;
}