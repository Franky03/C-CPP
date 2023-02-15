#include <iostream>

using namespace std;

bool ehEsparsa(int **matriz, int t1, int t2){
    int nZeros = 0;

    for(int i=0; i< t1; i++){
        for(int j=0; j<t2; j++){
            if(matriz[i][j] == 0){
                nZeros++;
            }
        }
    }

    return (nZeros > ((t1*t2)*0.7));
}


int main(void){
    int tamanho1, tamanho2;

    cin >> tamanho1;
    cin >> tamanho2;

    int **matriz = new int*[tamanho1];
    for(int i=0; i<tamanho1; i++){
        matriz[i] = new int[tamanho2];
    }

    for(int i=0; i<tamanho1; i++){
        for(int j=0; j<tamanho2; j++){
            cin >> matriz[i][j];
        }
    }

    if(ehEsparsa(matriz, tamanho1, tamanho2)){
        cout << "A matriz é esparsa"<<endl;
    }
    else {
        cout << "A matriz não é esparsa"<<endl;
    }

    // liberando a memória alocada para a matriz
    for(int i = 0; i<tamanho1; i++){
        delete[] matriz[i]; // liberando cada linha
    }
    delete[] matriz; // liberando o vetor de ponteiros


    return 0;
}