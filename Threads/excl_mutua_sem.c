#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> 

#define QTD_THREADS 5
#define VAR_LIMIT 100
int var_global = 0;
sem_t mutex;

void* incrementa(void* p){
    long id = (long) p;
    while(1){
        sem_wait(&mutex); // Protocolo de entrada
        var_global++;
        printf("[%ld] var_global = %d\n", id, var_global);

        if(var_global >= VAR_LIMIT) exit(0);
        sem_post(&mutex); // Protocolo de saída
    }
}

int main(){
    pthread_t threads[QTD_THREADS];
    sem_init(&mutex, 0, 1);
    for(long i = 0; i < QTD_THREADS; i++){
        pthread_create(&threads[i], NULL, incrementa, (void*) i);
    }
    for(int i = 0; i < QTD_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}

// Compilar: gcc -o excl_mutua_sem Threads/excl_mutua_sem.c -lpthread