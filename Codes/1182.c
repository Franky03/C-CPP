#include <stdio.h>

int main(void){
    int coluna;
    double matriz[12][12], total=0, result;
    char op;

    scanf("%d%*c", &coluna);
    scanf("%c", &op);

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    for(int j=0; j<12; j++){
        total += matriz[j][coluna];
    }

    result= (op == 'S') ? total : total/12;

    printf("%.1lf\n", result);
    

    return 0;
}