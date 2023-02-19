#include <iostream>

using namespace std;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int lerData(Data d1, Data d2){
    if(d1.ano < d2.ano) return 1;
    else if (d2.ano < d1.ano) return -1;
    else{
        if(d1.mes < d2.mes) return 1;
        else if(d2.mes < d1.mes) return -1;
        else {
            if (d1.dia < d2.dia) return 1;
            else if (d2.dia < d1.dia) return -1;
            else return 0;
        }
    }
}

int main(void){
    Data pessoa1, pessoa2;

    cin >> pessoa1.dia >> pessoa1.mes >> pessoa1.ano;
    cin >> pessoa2.dia >> pessoa2.mes >> pessoa2.ano;

    if(lerData(pessoa1, pessoa2) == 1) cout << "Pessoa 1 é mais velha" << endl;
    else if (lerData(pessoa1, pessoa2) == -1) cout << "Pessoa 2 é mais velha" << endl;
    else cout << "Pessoas são da mesma idade" << endl;

    return 0;
}