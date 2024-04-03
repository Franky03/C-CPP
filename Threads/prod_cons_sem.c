#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
int shared_mem;

void* producer(void* p){
    srand(time(NULL)); 
    while(1){
        int rand_num = rand() % 100;
        sem_wait(&empty);
        printf("[prod] %d\n", rand_num);
        shared_mem = rand_num;
        sleep(1);
        sem_post(&full);
    }
}

void* consumer(void* p){
    while(1){
        sem_wait(&full);
        printf("[cons] %d\n", shared_mem);
        sleep(1);
        sem_post(&empty);
    }
}

int main(){
    pthread_t prod, cons;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

// compile: g++ prod_cons_sem.c -o prod_cons_sem -lpthread