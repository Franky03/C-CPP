#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// typedef enum {false, true} boolean;

#define false 0
#define true 1

typedef struct {
    char descricao[31];
    float reais;
    int x;
    int y;
} Tesouro;

void tiraBarraN(char *str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i]=='\n'){
            str[i]= '\0';
        }
    }
}

void Mensagem(){
    printf("Ola, esse programa ...\n");
}

void Menu(){
    printf("\n\n =-=-=-= Opcoes =-=-=-=\n"
            "\n1-Cadastra\n2-Imprime\n3-Distancia a partir de um ponto\n4-Sair\n");
}

Tesouro *CadastraTesouro(Tesouro *reg){
    printf("Descricao: ");
    fflush(stdin);
    fgets(reg->descricao, 31, stdin);

    tiraBarraN(reg->descricao);
    printf("Reais: ");
    scanf("%f", &reg->reais);
    printf("X e Y: ");
    scanf("%d %d", &reg->x, &reg->y);
    return reg;
}

void ImprimeTesouro(const Tesouro *reg){
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Descricao\tReais\tX\tY\n");
    printf("\n%s\t", reg->descricao);
    printf("%.2f\t", reg->reais);
    printf("%d\t%d", reg->x, reg->y);
}

float Distancia(const Tesouro reg, int x, int y){
    float dist;
    dist= sqrt(pow(reg.x - x, 2) + pow(reg.y - y, 2));
    return dist;
}

int main(void){
    int cadastrou = false;
    Tesouro reg;
    int opc;
    int x, y;

    Mensagem();
    while(true){
        Menu();
        scanf("%d", &opc);
        if(opc==4){
            break;
        }

        switch(opc){
            case 1:
                CadastraTesouro(&reg);
                cadastrou = true;
                break;
            case 2:
                if(cadastrou)
                    ImprimeTesouro(&reg);
                else
                    puts("Cadastre um produto para imprimi-lo !");
                break;
            case 3:
                if(cadastrou){
                    printf("X e Y: ");
                    scanf("%d %d", &x, &y);
                    printf("Distancia: %.2f", Distancia(reg, x, y));
                }
                else puts("Cadastre um produto primeiro !");
                    break;
            default:
                puts("Opcao Invalida\n");
                break;
        }
    }

    puts("Adeus");  
    return 0;
}