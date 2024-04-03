#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define TAM_PALAVRA 5
#define QTD_PALAVRAS 100

pthread_barrier_t barreira_geracao_letras;
pthread_barrier_t barreira_verificacao_palindromo;

char palavra[TAM_PALAVRA + 1];

void* gera_letra(void* p){
    long id = (long) p;
    int count = 0;
    while(count < QTD_PALAVRAS) {
        time_t t;
        srand((unsigned) time(&t) + (int)id);
        int num = rand() % 26;
        char letra = 'a' + num;
        palavra[(int)id] = letra;
        sleep(1);
        printf("[%ld] gerou %c...\n", id, letra);
        pthread_barrier_wait(&barreira_geracao_letras);
        pthread_barrier_wait(&barreira_verificacao_palindromo);
        count++;

    }
}

int testa_palindromo(char* str, int tam) {
	int i, j;

	for (i = 0, j = tam-1; i < j; i++, j--) {
		if (str[i] != str[j]) {
//			printf("%c != %c\n", str[i], str[j]);
			return 0;
		}
	}
	return 1;
}

int main(void){
    pthread_t threads[TAM_PALAVRA];
	int palavra_count = 0;

        pthread_barrier_init(&barreira_geracao_letras, NULL, TAM_PALAVRA + 1);
        pthread_barrier_init(&barreira_verificacao_palindromo, NULL, TAM_PALAVRA + 1);

	for (long i = 0; i < TAM_PALAVRA; i++) {
		pthread_create(&threads[i], NULL, gera_letra, (void*)i);
	}

    while (palavra_count < QTD_PALAVRAS) {
		pthread_barrier_wait(&barreira_geracao_letras);
		palavra[TAM_PALAVRA] = '\0';
		printf("[main] testando se %s é palíndromo...\n", palavra);
		int res = testa_palindromo(palavra, TAM_PALAVRA);
		if (res) {
			printf("[main] %s é um palíndromo!\n", palavra);
            sleep(10);
		} else {
			printf("[main] %s não é um palíndromo!\n", palavra);
		}
		palavra_count++;
		pthread_barrier_wait(&barreira_verificacao_palindromo);
	}
    return 0;
}


// compilar com: g++ -o barreira_palindromo barreira_palindromo.c -lpthread


