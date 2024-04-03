#include "stdio.h"
#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"

sem_t sem;
int global=0;

void* funcaoCritica(void* id) {
    long di=(long)id;
    sem_wait(&sem); // Decrementa o semáforo
    printf("Thread %ld acessando recurso compartilhado.\n", di);
    global+=di;

    printf("Na thread %ld a variavel compartilhada eh: %d\n", di, global);

    sem_post(&sem); // Incrementa o semáforo
    
}

int main() {
    
    sem_init(&sem, 0, 2); // Inicializa o semáforo com contador 2

    pthread_t threads[10];

    for(int i=0;i<10;i++){
        pthread_create (&threads[i],NULL,funcaoCritica,(void*)i);
    }

    for(int i=0;i<10;i++){
        pthread_join(threads[i],NULL);
    }


    return 0;
}


// compilar com: gcc -o teste teste.c -lpthread -lrt