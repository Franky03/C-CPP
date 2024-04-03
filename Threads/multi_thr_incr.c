#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 10
#define INC_LIMIT 1000000

long var_global = 0;

void* incrementa(void* p){
    long id = (long)p;

    printf("[THREAD %ld] iniciando incremento\n", id);

    for(int i = 0; i < INC_LIMIT; i++){
        //var_global++; //! incremento não atômico -- problemas
        //__sync_fetch_and_add(&var_global, 1); //! incremento atômico
        printf("[THREAD %ld] incrementando var_global: %ld\n", id, var_global);
        __atomic_fetch_add(&var_global, 1, __ATOMIC_SEQ_CST); //! incremento atômico   
    }

}

int main(){
    pthread_t threads[NUM_THREADS];
    
    printf("[main] criando %d threads...\n", NUM_THREADS);
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, incrementa, (void *)i); // cria a thread
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL); //! espera a thread terminar
    }
    printf("[main] valor final de var global: %ld\n");
    return 0;
}