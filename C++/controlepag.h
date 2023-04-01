#include <iostream>
#include "controle.h"

class ControlePagamentos {
    private:
        Pagamento pagamentos[100];
        int indice;
    public:
        ControlePagamentos();
        void setPagamento(Pagamento pag, int indice);
        Pagamento getPagamento(int indice);
        double calculaTotalDePagamentos();
        int getIndexFuncionario(std::string nomeDoFuncionario);
  
};