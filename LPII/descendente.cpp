/*
Faça um programa em C/C++ que crie 10 processos que dormirão um tempo aleatório entre 5 e 20 segundos.
Faça o processo principal dormir por 10 segundos e depois faça-o finalizar todos os processos descedentes que ainda estiverem ativos (use a função kill() para finalizar os processos descendentes).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int main() {
    int i, pid, status;
    int processos = 10;

    
}