#include <iostream>
#include "invoice.h"
using namespace std;

Invoice::Invoice()
{
}

float Invoice::getInvoiceAmount()
{
    
    return preco * quant;

}

void readInv(Invoice *i){
    cin >> i->num;
    cin.ignore();
    getline(cin, i->descr);
    cin >> i->quant;
    cin >> i->preco;

    if(i->quant < 0)
        i->quant = 0;
    if(i->preco < 0)
        i->preco = 0;
}

void outInv(Invoice *i){
    cout << i->num << " - "<< i->descr << " - " << i->quant << " - " << i->preco << " - " << i->getInvoiceAmount() << endl;
}

int main(void){
    Invoice i1;
    Invoice i2;

    readInv(&i1);
    readInv(&i2);

    outInv(&i1);
    outInv(&i2);

    return 0;
}