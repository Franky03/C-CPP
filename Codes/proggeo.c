#include <stdio.h>
#include <math.h>

int main(){
    int t1, atual, r, n, soma;
    printf("t1 r n: ");
    scanf("%d%d%d", &t1, &r, &n);
    if(r<=1){
        printf("N invalido!\n");
        return 1;
    }
    atual= t1;

    for(int i=0; i<n; i++){
        printf("%d", atual);
        if(i!=n-1){
            printf(" ");
        }
        else{
            printf("\n");
        }
        atual *= r;
    }
    
    soma= t1* (pow(r, n)-1)/(r-1);

    printf("Soma: %d\n", soma);
    return 0;
}