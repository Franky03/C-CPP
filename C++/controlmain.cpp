#include <iostream>
#include "controlepag.h"

int main(void){
    ControlePagamentos controle;
    int n_pags;
    std::string nome;
    double valor;

    std::cin >> n_pags;

    for(int i=0; i<n_pags; i++){
        std::cin >> valor;
        std::cin.ignore();
        getline(std::cin, nome);

        Pagamento pag(valor, nome);

        controle.setPagamento(pag, i);
    }

    getline(std::cin, nome);
    int idx = controle.getIndexFuncionario(nome);
    if(idx == -1){
        std::cout << nome << " não encontrado(a)." << std::endl;
        std::cout << "Total: R$ " << (int) controle.calculaTotalDePagamentos() << std::endl;
        return 0;
    }

    Pagamento funcionario = controle.getPagamento(idx);
    
    std::cout << funcionario.getNomeDoFuncionario() << ": R$ " << (int) funcionario.getValorPagamento() << std::endl; 
    std::cout << "Total: R$ " << (int) controle.calculaTotalDePagamentos() << std::endl;


    return 0;
}