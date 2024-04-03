#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 8

int buffer[BUFFER_SIZE];

sem_t empty, full;
int front, rear;

void* producer(void* arg) {
    int item;
    srand(time(NULL));
    while (1) {
        item = rand() % 100;
        sem_wait(&empty);
        buffer[rear] = item;
        printf("[prod] %d\n", item);
        rear = (rear + 1) % BUFFER_SIZE;
        sem_post(&full);
        sleep(1);
    }
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);
        item = buffer[front];
        printf("[cons] %d\n", item);
        front = (front + 1) % BUFFER_SIZE;
        sem_post(&empty);
        sleep(1);
    }
}

int main(void){
    pthread_t prod, cons;
    front = rear = 0;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

// g++ -o shared_buff_sem shared_buff_sem.c -lpthread