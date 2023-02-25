#include <iostream>

using namespace std;

typedef struct {
    string nome;
    int numero;
    int votos=0;
} Classe;

bool validNumber(const int arr[], int num, int t){
    for(int i=0; i<t; i++){
        if(num == arr[i]){
            return true;
        }
    }
    return false;
}

Classe verifyWinner(const Classe arr[], int t){
    Classe champ = arr[0];
    for(int i=0; i<t; i++){
        if(arr[i].votos > champ.votos){
            champ = arr[i];
        }
    }
    return champ;
}

int main(void){
    int n_candidatos;

    cin >> n_candidatos;

    int numbers[n_candidatos];
    Classe candidatos[n_candidatos];

    for(int i=0; i<n_candidatos; i++){
        cin >> candidatos[i].numero;
        numbers[i] = candidatos[i].numero;
        cin.ignore();
        getline(cin, candidatos[i].nome);
    }

    int voto;
    int nulos=0;
    int total=0;

    while(true){
        cin >> voto;

        if(voto <= 0) break;

        total++;

        if (!validNumber(numbers, voto, n_candidatos)){
            nulos++;
            continue;
        } 

        for(int i=0; i<n_candidatos; i++){
            if (voto == candidatos[i].numero){
                candidatos[i].votos++;
            }
        }

    }
    
    cout.precision(2);
    Classe winner;
    winner = verifyWinner(candidatos, n_candidatos);
    for(int i=0; i<n_candidatos; i++){
        cout  << fixed << (double) candidatos[i].votos/ total *100 << " - " << candidatos[i].numero << " - " << candidatos[i].nome;
        if(candidatos[i].nome == winner.nome){
            cout << " VENCEDOR";
        }
        cout << endl;
    }
    cout << ( (float) nulos/total)*100 << " - Nulos" << endl;
}