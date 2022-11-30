#include <stdio.h>
#include <math.h>

int det2(const int ar[][2]){
    int det;
    det= (ar[0][0] * ar[1][1]) - (ar[0][1] * ar[1][0]);

    return det;
}

int det(const int ar[][3]){
    int D;
    int aux[2][2];

    int c_1, c_2, c_3;

    aux[0][0]= ar[1][1];
    aux[0][1]= ar[1][2];
    aux[1][0]= ar[2][1];
    aux[1][1]= ar[2][2];
    c_1= ar[0][0] * pow(-1, 0+0) * det2(aux);

    aux[0][0]= ar[1][0];
    aux[0][1]= ar[1][2];
    aux[1][0]= ar[2][0];
    aux[1][1]= ar[2][2];
    c_2= ar[0][1] * pow(-1, 0+1) * det2(aux);


    aux[0][0]= ar[1][0];
    aux[0][1]= ar[1][1];
    aux[1][0]= ar[2][0];
    aux[1][1]= ar[2][1];
    c_3= ar[0][2] * pow(-1, 0+2) * det2(aux);

    D= c_1 + c_2 + c_3;

    return D;
}

int main(void){
    int matriz[3][3]= {{3, 4, 6}, {1, 3, 8}, {3, 5, 9}};
    printf("%d\n", det(matriz));
    
    return 0;
}