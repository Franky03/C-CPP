#include <string>
#ifndef INVOICE_H
#define INVOCE_H

class Invoice{
    public:
        Invoice();

        // get methods;

        std::string getNum() const;
        std::string getDescr() const;
        int getQuant() const;
        float getPreco() const;

        // set methods;

        void setNum(std::string num);
        void setDescr(std::string descr);
        void setQuant(int quant);
        void setPreco(float preco);

        float getInvoiceAmount() const;
        void print() const;
    
    private:
        std::string numero;
        std::string descricao;
        int quantidade;
        float preco;
    
};

#endif
