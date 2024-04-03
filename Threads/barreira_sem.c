#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t arrive_1, arrive_2;

void* worker_1(void* p){
    while(1){
        time_t t;
        srand((time(&t)+1));
        int rnd = (rand()%8)+1;
        printf("[worker_1] job %d\n", rnd);
        
        sleep(rnd);
        printf("[worker_1] chegou na barreira\n");
        //barreira
        sem_post(&arrive_1); // libera a thread 2
        sem_wait(&arrive_2); // espera a thread 2

        printf("[worker_1] passou da barreira\n");
    }

}

void* worker_2(void* p){
    while(1){
        time_t t;
        srand((time(&t)+2));
        int rnd = (rand()%8)+1;
        printf("[worker_2] job %d\n", rnd);
        
        sleep(rnd);
        printf("[worker_2] chegou na barreira\n");
        //barreira
        sem_post(&arrive_2); // libera a thread 1
        sem_wait(&arrive_1); // espera a thread 1

        printf("[worker_2] passou da barreira\n");
    }

}

int main(void){
    pthread_t t1, t2;
    sem_init(&arrive_1, 0, 0);
    sem_init(&arrive_2, 0, 0);

    pthread_create(&t1, NULL, worker_1, NULL);
    pthread_create(&t2, NULL, worker_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

