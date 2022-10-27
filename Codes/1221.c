#include <stdio.h>
#include <math.h>

int main(void){
    int n, teste;
    long p;

    scanf("%ld", &n);

    for(int i=0; i<n; i++){
        teste=0; 
        scanf("%ld", &p);

        if(p==0 || p==1){
            printf("Not Prime\n", p);
            continue;
        }
        if (p==2){
            printf("Prime\n");
            continue;
        }
        for(int j=2; j< sqrt(p)+1; j++){
            if(p%j==0) teste++;
            if(teste==2) break;
        }

        if(teste >= 1) 
            printf("Not Prime\n");
        else 
            printf("Prime\n");
    }

    return 0;
}