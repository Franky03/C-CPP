#include <iostream>
#include "data3.h"

using namespace std;

int main(void){
    Data *d2;
    int dia, mes, ano, qtd;

    cin >> dia >> mes >> ano;

    d2 = new Data(dia, mes, ano);
    
    cin >> qtd;
    for(int i=0; i< qtd; i++){
        d2->nextDay();
    }

    d2->printData();
    delete d2;

    return 0;
}