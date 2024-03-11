#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define NUM_LETTERS 26
#define ASCII_A 65
#define NUM_FILES 10
#define MAX_KEY_SIZE 4

// Função para criptografar uma senha
char* encrypt(const char* str, int tamanho) {
    char* str_result = (char*) malloc(sizeof(char)*tamanho);
    for (int i = 0; i < tamanho; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int chave = str[i] - ASCII_A;
            str_result[i] = (str[i] - ASCII_A + chave) % NUM_LETTERS + ASCII_A;
        }
    }
    
    return str_result;
}

int main() {
    FILE *input_file = fopen("./keys.txt", "r");
    if (input_file == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        exit(1);
    }

    char linha[20];
    char original[MAX_KEY_SIZE + 1];
    char criptografada[MAX_KEY_SIZE + 1];


    while(fgets(linha, sizeof(linha), input_file) != NULL) {
        char *comma = strchr(linha, ',');
        if (comma == NULL) {
            fprintf(stderr, "Linha inválida: %s\n", linha);
            continue;
        }
        if(comma){
            *comma = '\0';
            strcpy(original, linha);
            strcpy(criptografada, comma+1);
            
            criptografada[strlen(criptografada)-1] = '\0';
            if(strcmp(encrypt(original, MAX_KEY_SIZE+1), criptografada) == 0){
                printf("Senha correta: %s\n", original);
            } else {
                printf("Senha incorreta: %s\n", original);
            }

            
        }
        
    }

    fclose(input_file);
    return 0;
    
}