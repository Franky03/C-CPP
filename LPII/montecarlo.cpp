/*
 Faça um programa em C/C++ para calcular o valor de pi usando o método de Monte Carlo. O programa deve solicitar a quantidade de processos e criar os processos descendentes - 
 cada um dos quais deve gerar um número aleatório de pontos e calcular o número de pontos que caem dentro do círculo unitário. 
 O processo principal deve então somar os resultados dos processos descendentes para obter uma estimativa do valor de pi.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    int n, i, pid, status;
    int total_pontos = 0;
    int processos = 0;
    double x, y, pi;

    cout << "Digite a quantidade de processos: ";   
    cin >> processos;

    int fd[2];
    if(pipe(fd) == -1) {
        cout << "Erro ao criar o pipe" << endl;
        exit(1);
    }

    for (i = 0; i < processos; i++) {
        pid = fork();
        cout << "Processo: " << i << " - PID: " << pid << endl;
        sleep(1);
        if (pid == 0) {
            srand(time(NULL)+getpid());
            int pontos = 0;

            for (n = 0; n < 1000000; n++) {
                x = (double)rand() / RAND_MAX;
                y = (double)rand() / RAND_MAX;
                if (sqrt(x*x + y*y) <= 1) {
                    pontos++;
                }
            }
            close(fd[0]);
            write(fd[1], &pontos, sizeof(pontos));
            close(fd[1]);
            exit(EXIT_SUCCESS);
        }
    }

    close(fd[1]);

    for (i = 0; i < processos; i++) {
        wait(&status);
        int pontos;
        read(fd[0], &pontos, sizeof(pontos));
        total_pontos +=  pontos;
    }

    close(fd[0]);

    pi = 4.0 * total_pontos / (1000000 * processos);
    cout << "Valor de pi: " << pi << endl;

    return 0;
}