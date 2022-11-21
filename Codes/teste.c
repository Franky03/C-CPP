#include <stdio.h>

int imprimeMatriz(const int m[][3], int t1, int t2){
    for(int i=0; i<t1; i++){
        for(int j=0; j<t2; j++){
            printf("%d ", m[i][j]);
        }
        puts("");
    }
}

int main(void){
    int arr[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
    imprimeMatriz(arr, 3, 3);
    

    return 0;
}