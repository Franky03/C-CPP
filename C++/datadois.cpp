#include <iostream>
#include <string>
using namespace std;

class Data {
    private:
        int mes;
        int dia; 
        int ano;
        string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", 
                            "Maio", "Junho", "Julho", "Agosto", 
                            "Setembro", "Outubro", "Novembro", "Dezembro"};
    public:
        Data() {
            dia = 1;
            mes = 1;
            ano = 1;
        }

        void set(int i, char what){
            if(what== 'd') dia = i;
            else if(what == 'm') mes = i;
            else ano = i;
        }
        
        int get(char what) {
            if(what == 'd') return dia;
            else if(what == 'm') return mes;
            else return ano ;
        }

        void printData() {
            string mesNome = (get('m') <=12) ? meses[mes - 1] : "Indefinido";
            cout << get('d') << " de " << mesNome << " de " << get('a') << endl;
        }

};

int main(void){
    Data data;
    int dia_, mes_, ano_;
    cin >> dia_ >> mes_ >> ano_;

    data.set(dia_, 'd');
    data.set(mes_, 'm');
    data.set(ano_, 'a');

    data.printData();
    

    return 0;
}