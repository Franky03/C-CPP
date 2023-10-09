#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countone(const char *input) {
    int  count = 0;
    
    for(int i=0; i < strlen(input); i++) {
        if(input[i] == '1') {
            count++;
        }
    }
    return count;
}

char* decimalToBinary(int decimal) {
    char *binario = (char *)malloc(5);

    if (binario == NULL) {
        perror("Erro de alocação de memória");
        exit(EXIT_FAILURE);
    }

    binario[4] = '\0';

    for (int i = 3; i >= 0; i--) {
        binario[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }

    return binario;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    

    for(int i=0; i < strlen(input); i++) {
        if(input[i] != '0' && input[i] != '1') {
            printf("Invalid input\n");
            return 1;
        }
    }

    int count = countone(input);
    char* binary = decimalToBinary(count);

    // crie um arquivo com o nome output.txt e escreva o resultado
    FILE *fp = fopen("../countone.tv", "a");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp, "%s_%s\n", input, binary);
    fclose(fp);

    printf("%s_%s\n", input, binary);

    return 0;
}