#include <stdio.h>

int main(){
    float notas[4], media_geral, nota_exame;

    for(int i=0; i<4; i++)
    {
        scanf("%f", &notas[i]);
    }

    notas[0] *= 2;
    notas[1] *= 3; 
    notas[2] *= 4;
    notas[3] *= 1;

    for(int j=0; j<4; j++)
    {
        media_geral += notas[j];
    }

    media_geral /= 10;

    printf("Media: %.1f\n", media_geral);

    if(media_geral>=7.0)
    {
        printf("Aluno aprovado.\n");
    }
    else if(media_geral<5.0)
    {
        printf("Aluno reprovado.\n");
    }
    else if(media_geral>=5 && media_geral<=6.9)
    {
        printf("Aluno em exame.\n");
        scanf("%f", &nota_exame);

        printf("Nota do exame: %.1f\n", nota_exame);

        media_geral += nota_exame;
        media_geral /= 2;

        if(media_geral>=5.0)
        {
            printf("Aluno aprovado.\n");
        }
        else if(media_geral<=4.9)
        {
            printf("Aluno reprovado.\n");
        }

        printf("Media final: %.1f\n", media_geral);
    }
    
    return 0;
}