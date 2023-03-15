#include <iostream>
#include "invoice2.h"

Invoice::Invoice()
{   
}

std::string Invoice::getNum() const {
    return numero;
}

std::string Invoice::getDescr() const {
    return descricao;
}

int Invoice::getQuant() const {
    return quantidade;
}

float Invoice::getPreco() const {
    return preco;
}

void Invoice::setNum(std::string num){
    numero = num;
}

void Invoice::setDescr(std::string descr){
    descricao = descr;
}

void Invoice::setQuant(int quant){
    if(quant<0) quantidade = 0;
    else quantidade = quant;
}

void Invoice::setPreco(float preco_){
    if(preco_ < 0) preco = 0.0;
    else this->preco = preco_;
}

float Invoice::getInvoiceAmount() const {
    return quantidade * preco;
}
// 100 - Teclado USB - 2 - 143.9 - 287.8
void Invoice::print() const {
    std::cout   << numero << " - " 
                << descricao << " - " 
                << quantidade << " - " 
                << preco << " - " 
                << getInvoiceAmount() << std::endl;
}