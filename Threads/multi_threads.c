#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 5

typedef struct {
    long id;
    int count;
} param_t;

void *funcao_thread(void *p){
    param_t *param = (param_t *) p;

    printf("[%ld] iniciando contamgem (%d)\n", param->id, param->count);
    for(int i = 0; i < param->count; i++){
        printf("[%ld] contagem: %d\n", param->id, i);
        sleep(1);
    }
    printf("[%ld] finalizando contagem\n", param->id);

    pthread_exit((void *)param->id);
}

int main(){
    pthread_t threads[NUM_THREADS];
    param_t params[NUM_THREADS];
    
    printf("[MAIN] criando %d threads...\n", NUM_THREADS);
    for(int i = 0; i < NUM_THREADS; i++){
        params[i].id = i;
        params[i].count = rand() % 10 + 1;
        pthread_create(&threads[i], NULL, funcao_thread, (void *)&params[i]); // cria a thread
    }
    for(int i = 0; i < NUM_THREADS; i++){
        long id;
        pthread_join(threads[i], (void **)&id); //! espera a thread terminar
        printf("[MAIN] thread %ld finalizada\n", id);
    }
    printf("[MAIN] finalizando programa ... \n");
    return 0;
}