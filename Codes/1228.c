#include <stdio.h>

int main(void){
    int largada[24];
    int chegada[24];
    int comp[24];
    int fim, n, aux;

    while (scanf("%d", &n) != EOF)
    {
        fim=0;
        for(aux=0; aux<n; aux++){
            scanf("%d", &largada[aux]);
        }
        aux=0;
        for(aux=0;aux < n;aux++){
            scanf("%d", &chegada[aux]);
        }

        for(int i=0; i< n; i++){
            for(int j= 0; j<n; j++){
                if(largada[i]==chegada[j]){
                    comp[j] = i + 25;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(comp[i]> comp[j]){
                    aux= comp[j];
                    comp[j]=comp[i];
                    comp[i]= aux;
                    fim++;
                }
            }
        }
        printf("%d\n", fim);
    }
    

    return 0;
}