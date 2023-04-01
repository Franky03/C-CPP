#include <iostream>
#include "controle.h"

Pagamento::Pagamento()
{
    setValorPagamento(0);
    setNomeDoFuncionario("");
}

Pagamento::Pagamento(double valorPagamento, std::string nomeDoFuncionario)
{
    setValorPagamento(valorPagamento);
    setNomeDoFuncionario(nomeDoFuncionario);
}

void Pagamento::setValorPagamento(double valorPagamento)
{
    this->valorPagamento = valorPagamento;
}

void Pagamento::setNomeDoFuncionario(std::string nomeDoFuncionario)
{
    this->nomeDoFuncionario = nomeDoFuncionario;
}

double Pagamento::getValorPagamento()
{
    return valorPagamento;
}

std::string Pagamento::getNomeDoFuncionario()
{
    return nomeDoFuncionario;
}