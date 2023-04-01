#include <iostream>

class Pagamento {
    private:
        double valorPagamento;
        std::string nomeDoFuncionario;
    public:
        Pagamento();   
        Pagamento(double valorPagamento, std::string nomeDoFuncionario);
        void setValorPagamento(double valorPagamento);
        void setNomeDoFuncionario(std::string nomeDoFuncionario);
        double getValorPagamento();
        std::string getNomeDoFuncionario();
};