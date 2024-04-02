#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

sem_t mutex;
pthread_t tid[2];

void* trythis(void* arg){
    sem_wait(&mutex);
    __intptr_t i = (__intptr_t)arg;
    printf("\nEntered..\n");

    printf("[*] Thread %ld\n", i );
    sleep(1);

    printf("\nJust Exiting...\n");
    sem_post(&mutex);
    return NULL;
}

int main(){
    __intptr_t i = 0;
    int error;

    if(sem_init(&mutex, 0, 1) != 0 ){
        printf("\nSemaphore initialization failed\n");
        return 1;
    }

    for(i = 0; i < 10; i++){
        error = pthread_create(&(tid[i]), NULL, &trythis, (void*)i);
        if (error != 0)
            printf("\nThread can't be created :[%s]", strerror(error));
    }

    for(i = 0; i< 10; i++){
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}