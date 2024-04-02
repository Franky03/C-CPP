#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
int shared_var; //buffer

void *producer(void *arg){
    time_t t;
    srand(time(&t) + 1);

    while(1){
        sem_wait(&empty); // protocolo de entrada
        int data = rand() % 256;
        printf("[producer] generated: %d\n", data);
        sleep(1);
        shared_var = data;
        sem_post(&full); // protocolo de saída

    }

}

void *consumer(void *arg){
    time_t t;
	srand(time(&t)+2);

    while(1){
        sem_wait(&full); // protocolo de entrada
        int data = shared_var;
        printf("[consumer] consumed: %d\n", data);
        sleep(1);
        sem_post(&empty); // protocolo de saída
    }

}

int main(void){
    pthread_t prod, cons;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}