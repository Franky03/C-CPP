#include <stdio.h>

int main(void){
    int n;
    int ar[5]= {0};
    scanf("%d", &n);

    int lista[n];
    for(int i=0; i<n; i++){
        scanf("%d", &lista[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=2; j<6; j++){
            if(lista[i]% j== 0){
                ar[j-1]++;
            }
        }
    }

    for(int i= 2; i<6; i++){
        printf("%d Multiplo(s) de %d\n", ar[i-1], i);
    }
    return 0;
}