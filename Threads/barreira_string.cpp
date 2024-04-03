#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <pthread.h>

#define QTD_THREADS 5

pthread_barrier_t barrier_str;

using std::cout;
using std::endl;
using std::string;
using std::thread;

string hash[QTD_THREADS];

class hash_gen {
    int size;
    public:
        hash_gen(int s): size(s) {}
        string& gethash(int pos){
            const string charset = "abcdefghijklmnopqrstuvwxyz";
            string random_string;
            std::srand(std::time(0));
            for (int i = 0; i < size; i++) {
                random_string += charset[std::rand() % charset.length()];
            }
            hash[pos] = random_string;
            
            cout << "[" << pos << "] " << hash[pos] << endl;
            pthread_barrier_wait(&barrier_str);
        }

};

int main(void){
    thread* threads[QTD_THREADS];
    hash_gen h(10);
    pthread_barrier_init(&barrier_str, NULL, QTD_THREADS+1);

    for(int i = 0; i < QTD_THREADS; i++){
        threads[i] = new thread(&hash_gen::gethash, &h, i);
    }   

    pthread_barrier_wait(&barrier_str);
    cout << "hash gerado : " << endl;
    for(int i = 0; i < QTD_THREADS; i++){
        cout << "[" << i << "] " << hash[i] << endl;
    }

    for(int i = 0; i < QTD_THREADS; i++){
        threads[i]->join();
        delete threads[i];
    }

    pthread_barrier_destroy(&barrier_str);
    return 0;
}

// compile: g++ -std=c++11 -pthread -o barreira_string barreira_string.cpp