#include <iostream>

using namespace std;

int main(void){
    int salario=0, emprestimo=0, parcelas =0;
    
    cin >> salario;
    if(salario<=0) {
        while (salario<=0)
        {
            cin >> salario;
        }
    }
    cin >> emprestimo;
    if(emprestimo<=0){
        while (emprestimo<=0)
        {
            cin >> emprestimo;
        }
    }
    cin >> parcelas;
    if(parcelas<=0){
        while(parcelas <= 0)
        {
            cin >> parcelas;
        }
    }
    
    double check = (float) salario * 0.3;
    if((double) emprestimo / parcelas < check) 
        cout << "Emprestimo pode ser concedido" << endl;
    else 
        cout << "Emprestimo nao pode ser concedido" << endl;


    return 0;
}