#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <process.h>
#include <string.h>
#include <conio.h>

typedef struct item {
    int x;
    int y;
} tipoItem;

typedef struct celula
{
    struct celula *prox;
    struct celula *ant;
    tipoItem item;
} Celula;

typedef struct recorde
{
    char *nome;
    float pontos;
    int level;
} Recorde;

typedef struct lista 
{
    Celula *primeiro;
    Celula *ultimo;

} Lista;

typedef struct
{
    char  **mat;
    Lista posicoes;
    int flag;
    int xAlvo;
    int yAlvo;
    int pontos;
    int ultimove;
    float speed;
    char nome[30];
    int last_x;
    int last_y;
    int corFundo;
    int corSnake;
    int corSemente;
    int corParede;
    int corLetraPlacar;
    int corFundoPlacar;
    int jogoLevel;
    int jogoseeds;
    Recorde recorde;
    int dificuldade;
    Lista blocos;
} Jogo;

void FLVazia (Lista *lista){
    lista -> primeiro = (Celula*) malloc(sizeof(Celula));
    lista -> ultimo = lista -> primeiro;
    lista -> ultimo -> prox = NULL;
    lista -> primeiro -> ant = NULL;
    
}

int Vazia(Lista list){
    return (list.primeiro == list.ultimo);
}

void Insere(Lista *lista, tipoItem X){
    lista -> ultimo -> prox = (Celula*) malloc(sizeof(Celula));
    lista -> ultimo -> prox -> ant = lista -> ultimo;
    lista ->ultimo = lista -> ultimo -> prox;
    lista -> ultimo -> item = X;
}

void LimparMatriz(Jogo *jogo){
    for(int i=0; i<20; i++){
        for(int j=0; j<50; j++){
            jogo->mat[i][j] = ' ';
        }
    }
}

char **FazMatriz(int linhas, int colunas){
    char **m = (char**) malloc(linhas * sizeof(char*));
    for(int i=0; i< linhas; i++){
        m[i] = (char*) malloc(colunas * sizeof(char*));
        for(int j=0; j<colunas; j++){
            m[i][j]= ' ';
        }
    }

    return m;
}

 void marcaJogo(Jogo *jogo){
    int x,y, cont= 0;

    Celula *aux = jogo -> posicoes.primeiro;
    while(aux != NULL){
        x= aux -> item.x;
        y= aux -> item.y;
        if(cont==0)
        {
            jogo -> mat[x][y] = 178; // Codigo tabela ascii
            cont++;

        }
        else {
            jogo -> mat[x][y]= 177;
        }
        aux = aux -> prox;

    }
    jogo -> mat[jogo->xAlvo][jogo->yAlvo] = '*';

    aux= jogo -> blocos.primeiro->prox;
    while (aux != NULL)
    {
        jogo -> mat[aux->item.x][aux->item.y]= 'P';
        aux= aux->prox;
    }
    
 }

void Baixo(Jogo * jogo){
    if((jogo->posicoes.primeiro->item.x + 1) <20 && jogo->dificuldade > 3){
        Celula *aux = jogo -> posicoes.ultimo;
        while (aux->ant!=NULL)
        {
            aux->item.x = aux->ant-> item.x;
            aux->item.y = aux->ant-> item.y;
            aux = aux -> ant;
        }
        jogo -> mat[jogo->posicoes.primeiro -> item.x][jogo->posicoes.primeiro -> item.y]= ' ';
        jogo -> posicoes.primeiro ->item.x++;
        jogo -> ultimove = 80;
    }
    else if(jogo->dificuldade <=3){
        Celula *aux = jogo->posicoes.ultimo;
        while(aux->ant != NULL){
            aux -> item.x = aux->ant->item.x;
            aux -> item.y = aux->ant->item.y;
            aux= aux->ant;
        }
        jogo -> mat[jogo->posicoes.primeiro -> item.x][jogo->posicoes.primeiro -> item.y]= ' ';
        if((jogo ->posicoes.primeiro->item.x + 1) < 20){
            jogo -> posicoes.primeiro ->item.x++;
        }
        else{
            jogo -> posicoes.primeiro ->item.x = 0;
        }
        jogo-> ultimove = 80;
    }
    else jogo->flag = -1;
}

int main(void){
    
    

    return 0;
}