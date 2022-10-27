#include <stdio.h>

void value(float *player, int attack, int defense, int nivel, int bonus)
{
    float val = (attack + defense)/2;
    if(nivel%2 == 0){
        val += bonus;
    }

    *player= val;
}

int main(void){
    int vezes;
    float guarte, dabriel;
    int ai, di, li, bonus;

    scanf("%d", &vezes);
    for(int i=0; i<vezes; i++){
        scanf("%d", &bonus);

        scanf("%d%d%d", &ai, &di, & li);
        value(&dabriel ,ai, di, li, bonus);
        scanf("%d%d%d", &ai, &di, & li);
        value(&guarte, ai, di, li, bonus);

        if (dabriel>guarte)
            puts("Dabriel");
        else if(guarte>dabriel)
            puts("Guarte");
        else
            puts("Empate");

    }


    return 0;
}