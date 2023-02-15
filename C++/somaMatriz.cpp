#include <iostream>

using namespace std;

void somaMatriz(const int A[][10], const int B[][10], int m, int n){
    int C[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    int m, n;

    cin >> m >> n;

    int matrizA[10][10];
    int matrizB[10][10];

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> matrizA[i][j];
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> matrizB[i][j];
        }
    }

    somaMatriz(matrizA, matrizB, m, n);
    
    return 0;
}