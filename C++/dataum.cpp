#include <iostream>
using namespace std;

class Data {
    public:
        int mes;
        int dia; 
        int ano;

        Data() {
            dia = 1;
            mes = 1;
            ano = 1;
        }
};

int main(void){
    Data data;
    cin >> data.dia >> data.mes >> data.ano;

    cout << data.dia << "/" << data.mes << "/" << data.ano << endl; 
    

    return 0;
}