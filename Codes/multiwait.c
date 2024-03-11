#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>


int main(void){
    int qtd;
    int original_pid;
    int *child_pid;

    printf("Digite a quantidade de processos filhos: ");
    scanf("%d", &qtd);

    original_pid = getpid();

    if(getpid() == original_pid){
        child_pid = (int *) malloc(qtd * sizeof(int));
        for(int i=0; i<qtd; ++i){
            if(getpid() == original_pid){
                int r = fork();
                
            }
        }
    }




    return 0;
}

