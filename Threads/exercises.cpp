#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <pthread.h>


std::atomic<int> contador_atomico(0);
int contador_mutex = 0;
int contador_trava = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
std::atomic_flag flag = ATOMIC_FLAG_INIT;

void incrementa_atomico(int incrementos, int thread_id){
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < incrementos; i++){
        contador_atomico.fetch_add(1, std::memory_order_seq_cst);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Tempo de execução (Atomico) na thread " << thread_id << ": " << duration << " microsegundos" << std::endl;
}

void incrementa_mutex(int incrementos, int thread_id){
    auto start_time = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < incrementos; i++){
        pthread_mutex_lock(&mutex);
        contador_mutex++;
        pthread_mutex_unlock(&mutex);
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Tempo de execução (Mutex) na thread " << thread_id << ": " << duration << " microsegundos" << std::endl;
}

void incrementa_trava(int incrementos, int thread_id){
    auto start_time = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < incrementos; i++){
        while(atomic_flag_test_and_set(&flag)) {};
        contador_trava++;
        atomic_flag_clear(&flag);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Tempo de execução (Trava) na thread " << thread_id << ": " << duration << " microsegundos" << std::endl;
}   

int main(int argc, char *argv[]){
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <NUM_THREADS> <NUM_INCREMENTS>" << std::endl;
        return 1;
    }

    int NUM_THREADS = std::stoi(argv[1]);
    int NUM_INCREMENTS = std::stoi(argv[2]);

    std::thread threads[NUM_THREADS];

    // Teste com diferentes métodos de incremento
    for(int i = 1; i < NUM_THREADS; i++){
        std::cout << "Número de threads: " << i << std::endl;
        std::cout << "Número de incrementos: " << NUM_INCREMENTS << std::endl;

        //std::cout << "Atomico: " << std::endl;
        for(int j = 0; j < i; j++){
            threads[j] = std::thread(incrementa_atomico, NUM_INCREMENTS / i, j);
        }

        for(int j = 0; j < i; j++){
            threads[j].join();
        }

        //std::cout << "Mutex: " << std::endl;
        for(int j = 0; j < i; j++){
            threads[j] = std::thread(incrementa_mutex, NUM_INCREMENTS / i, j);
        }

        for(int j = 0; j < i; j++){
            threads[j].join();
        }

        //std::cout << "Trava: " << std::endl;
        for(int j = 0; j < i; j++){
            threads[j] = std::thread(incrementa_trava, NUM_INCREMENTS / i, j);
        }

        for(int j = 0; j < i; j++){
            threads[j].join();
        }
        
    }

    return 0;
}