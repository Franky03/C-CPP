#include <stdio.h>

char higher(int x, int y){
    int rafael= ((3*x)*(3*x)) + (y*y);
    int beto= 2*(x*x) + ((5*y)*(5*y));
    int carlos= (-100 * x )+ (y*y*y);

    if(rafael> beto && rafael>carlos){
        return 'r';
    }
    else if(beto> rafael && beto> carlos){
        return 'b';
    }
    else if(carlos> rafael && carlos> beto){
        return 'c';
    }
    
    return 'n';
    
}

int main(void){
    int vezes, x, y;
    char champ;

    scanf("%d", &vezes);
    for(int i=0; i<vezes; i++){
        scanf("%d%d", &x, &y);
        champ= higher(x, y);

        if(champ=='r')
            printf("Rafael ganhou\n");
        else if(champ=='b')
            printf("Beto ganhou\n");
        else if(champ=='c')
            printf("Carlos ganhou\n");
    }

    return 0;
}