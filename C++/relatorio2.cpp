#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct {
    char descricao[50];
    float peso;
    char tipo;

} Movel;

int main(void){

    int nMoveis;

    cin >> nMoveis;

    Movel moveis[nMoveis];

    for(int i=0; i< nMoveis; i++){
        cin.ignore();
        cin.getline(moveis[i].descricao, 50);
        cin >> moveis[i].peso >> moveis[i].tipo;
    }

    Movel mais_pesado = moveis[0];
    int termina_real= 0;
    int acima_10 = 0;

    for(int i=0; i<nMoveis; i++){
        if(moveis[i].peso > mais_pesado.peso){
            mais_pesado = moveis[i];
        }
        
        if(strcmp(moveis[i].descricao + strlen(moveis[i].descricao) - 4, "Real") == 0){
            termina_real++;
        }

        if(moveis[i].tipo=='s' && moveis[i].peso > 10){
            acima_10++;
        }
    }

    cout<< "Tipo 's' acima de 10Kg: " << acima_10 << endl;
    cout<< "Termina em  \"Real\": " << termina_real << endl;
    cout<< "Mais pesado: \""<< mais_pesado.descricao << "\"" <<endl;


    return 0;
}