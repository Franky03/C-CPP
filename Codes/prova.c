#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} Node;

void libera(Node ***bb, int a, int b){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            free(bb[i][j]);
        }
        free(bb[i]);
    }
    free(bb);

}

int main(void){
    Node *b;
    b = (Node*)malloc(9*sizeof(Node));


    
}