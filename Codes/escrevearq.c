#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[31];
    int idade;

} Pessoa;

int main(void){
    // Pessoa p;
    // FILE *entrada = fopen("entrada.bin", "ab");

    // scanf("%s", p.nome);
    // scanf("%d", &p.idade);

    // // O que voce quer salvar no arquivo, tamanho da estrutura, quantidade de objetos para serem escritos, arquivo onde salvar
    // fwrite(&p, sizeof(Pessoa), 1, entrada);

    // fclose(entrada);

    // FILE *ler= fopen("entrada.bin", "rb");
    // if(!ler){
    //     printf("ERRO NA LEITURA");
    // }

    // while(1){
    //     fread(&p, sizeof(Pessoa), 1, ler);
    //     if (feof(ler))
    //         break;
    //     printf("Pessoa %s > Idade %d\n", p.nome, p.idade);
    // }

    // fclose(ler);
    FILE *fp;
    int i, q;


    fp = fopen("saida.dat", "rb");
    if (fp == NULL){
        puts("Erro ao abrir o arquivo.");
        return 1;
    }

    fseek(fp, -sizeof(int), SEEK_END);
    while(1){
        q = fread(&i, sizeof(int), 1, fp);
        //printf("unidades lidas: %d\n", q);
        printf("i = %d\n", i);
        if (ftell(fp) == sizeof(int))
            break;
        fseek(fp, -2*sizeof(int), SEEK_CUR);
    }

    fclose(fp);
    return 0;

}