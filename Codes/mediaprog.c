#include <stdio.h>
#include <math.h>

int main(void){
    float labnota;
    float teonota;
    float media1, media_geral;
    char conceito;
    
    media_geral=0;
    for(int i=1; i<=3; i++){
        printf("Digite a nota da %d prova da Teoria: ", i);
        scanf("%f", &teonota);
        printf("Digite a nota da %d prova do Laboratorio: ", i);
        scanf("%f", &labnota);
        
        if (teonota>labnota){
            media1= (4*teonota + 6*labnota) / 10;
        }
        else{
            media1= (6*teonota + 4*labnota) / 10;
        }

        media_geral += media1;
        printf("Media %d: %.1f \n",i, media1);
    }

    media_geral= media_geral/3;

    printf("Media Geral : %.1f \n", media_geral);

    if (media_geral>=9 && media_geral<=10){
        conceito= 'A';
    }
    else if(media_geral>=8 && media_geral<9){
        conceito= 'B';
    }
    else if(media_geral>=7 && media_geral<8){
        conceito= 'C';
    }
    else if(media_geral>=6 && media_geral<7){
        conceito= 'D';
    }
    else if(media_geral>=5 && media_geral<6){
        conceito= 'E';
    }
    else if(media_geral<5){
        conceito= 'F';
    }
    printf("Conceito: %c", conceito);

    return 0;
}