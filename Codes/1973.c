#include <stdio.h>

int main() {

    int i, qFazendas, maior = 0, contador = 0;
    long long ovelhasNRoubadas = 0;

    scanf("%d", &qFazendas);

    int estrelas[qFazendas];

    for(i = 0; i < qFazendas; i++) {
        scanf("%d", &estrelas[i]);
    }

    i = 0;
    while(1) {
        if(estrelas[i] % 2 == 1) {
            if(estrelas[i] == 1) {
                contador += 1;
            }
            if(i < (qFazendas - 1)) {
                i += 1;
            }else{
                break;
            }
        }else {
            ovelhasNRoubadas -= ((2 * (i + 1)) - (1 + contador));
            break;
        }
    }
    
    if(estrelas[i] % 2 == 1) {
        ovelhasNRoubadas -= i + 1;
    }
    maior = i + 1;

    for(i = 0; i < qFazendas; i++) {
        ovelhasNRoubadas += estrelas[i];
    }

    printf("%d %lld\n", maior, ovelhasNRoubadas);

    return 0;
}