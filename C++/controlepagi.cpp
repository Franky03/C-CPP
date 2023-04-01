#include <iostream>
#include "controlepag.h"

ControlePagamentos::ControlePagamentos(){
    indice = 0;
}

void ControlePagamentos::setPagamento(Pagamento pag, int idx){
    pagamentos[idx] = pag;
    indice++;
}

Pagamento ControlePagamentos::getPagamento(int idx){
    return pagamentos[idx];
}

double ControlePagamentos::calculaTotalDePagamentos(){
    double total = 0;
    for(int i = 0; i < indice; i++){
        total += pagamentos[i].getValorPagamento();
    }
    return total;
}

int ControlePagamentos::getIndexFuncionario(std::string nomeFuncionario){
    for(int i=0; i<indice; i++){
        if(pagamentos[i].getNomeDoFuncionario().find(nomeFuncionario) != std::string::npos){
            return i;
        }
    }
    return -1;
}
