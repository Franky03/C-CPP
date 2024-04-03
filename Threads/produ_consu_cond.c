#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

int buffer[BUFFER_SIZE];
int insert_index = 0;
int remove_index = 0;

void* producer(void* p){
    int msg = 1;
    while(1){
        pthread_mutex_lock(&mutex);
        while((insert_index + 1) % BUFFER_SIZE == remove_index){
            pthread_cond_wait(&buffer_full, &mutex); // buffer cheio, esperar consumidor consumir
        } 
        printf("Mensagem enviada: %d\n", msg);
        sleep(1);
        buffer[insert_index] = msg++;
        insert_index = (insert_index + 1) % BUFFER_SIZE;
        pthread_cond_signal(&buffer_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* p){
    while(1){
        pthread_mutex_lock(&mutex);
        while(insert_index == remove_index){
            pthread_cond_wait(&buffer_empty, &mutex);
        } // buffer vazio esperar produtor produzir

        printf("Mensagem recebida: %d\n", buffer[remove_index]);
        sleep(1);
        remove_index = (remove_index + 1) % BUFFER_SIZE;
        pthread_cond_signal(&buffer_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void){
    pthread_t prod, cons;
    
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}

// compilar: g++ -o produ_consu_cond produ_consu_cond.c -lpthread