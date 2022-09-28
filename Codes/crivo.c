#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    int limite, raiz, total=0;

    scanf("%d", &limite);
    int inicio= time(NULL);
    int *vector;
    vector= malloc (limite * sizeof (int));

    raiz= (int) sqrt(limite);

    for (int i=2; i<=limite; i++){
        vector[i]= i;
    }
    
    for(int i=2; i<=raiz; i++){
        for(int j=i+i; j<=limite; j+=i){
            vector[j]=0;
        }
    }

    for(int i=2; i<=limite; i++){
        if(vector[i])
            total++;
    }

    int fim= time(NULL);

    printf("%d primos em %d s", total, fim-inicio);

    
    return 0;
}