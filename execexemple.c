#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){
    int fork_return;
    int x;
    printf("Avant exec\n");

    scanf("%d", &x);

    fork_return = fork();
    if(fork_return > 0){
        printf("fin du père (processus %d)\n", getpid());
    } else {
        printf("Je suis le fils (processus %d)\n", getpid());
        execve("lpii", NULL, NULL);
        printf("Après exec\n");
    }

    
    return 0;
}