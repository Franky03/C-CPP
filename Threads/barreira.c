#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define QTD_THREADS 8
#define QTD_PARTS 5

pthread_barrier_t barrreira_render;
pthread_barrier_t barrreira_print;

int img_parts[QTD_THREADS];

void* render_img_part(void* p){
    int count = 0;
    long id = (long)p;
    while(count < QTD_PARTS){
        printf("[%ld] renderizando parte %d\n", id, count);
        time_t t;
        srand(time(&t) + id);
        int my_render = rand() % 255;
        img_parts[id] = my_render;
        sleep((int)id + 1);
        printf("[%ld] chegou nas barreiras\n", id);
        pthread_barrier_wait(&barrreira_render);
        pthread_barrier_wait(&barrreira_print);
        printf("[%ld] saindo das barreiras\n", id);
        count++;
    }
}

int main(void){
    pthread_t threads[QTD_THREADS];
    int count = 0;

    pthread_barrier_init(&barrreira_render, NULL, QTD_THREADS+1);
    pthread_barrier_init(&barrreira_print, NULL, QTD_THREADS+1);

    printf("[main] renderizando %d imagens em %d partes ...\n", QTD_PARTS, QTD_THREADS);
    for(long i = 0; i < QTD_THREADS; i++){
        pthread_create(&threads[i], NULL, render_img_part, (void*)i);
    }
    while (count < QTD_PARTS){
        pthread_barrier_wait(&barrreira_render);
        printf("exibindo quadro #%d: \n", count);
        for (int i = 0; i < QTD_THREADS; i++) {
			printf("[%d] %d\n", i, img_parts[i]);
            sleep(1);
		}

        pthread_barrier_wait(&barrreira_print);
        count++;

    }
    return 0;
    
}