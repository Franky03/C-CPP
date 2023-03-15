#include <string>
#ifndef INVOICE_H
#define INVOCE_H

class Invoice{
    public:
        int num;
        std::string descr;
        int quant;
        double preco;
    
        Invoice();
        float getInvoiceAmount();
        
};

#endif
