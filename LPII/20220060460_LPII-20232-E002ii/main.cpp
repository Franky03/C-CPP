#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <random>

using namespace std;

#define MAX_ITEMS 10

struct myqueue {
    int item;
    struct myqueue *next;
};

typedef struct myqueue Node;

struct items {
    Node *front;
    Node *rear;
    int size;
};

typedef struct items Items;

Node* new_node(int item){
    Node *temp = new Node;
    temp->item = item;
    temp->next = NULL;
    return temp;
}

Items* create_items(){
    Items *temp = new Items;
    temp->front = temp->rear = NULL;
    temp->size = 0;
    return temp;
}

void insertItem(Items **head, int item){
    Node *temp = new_node(item);
    if((*head)->rear == NULL){
        (*head)->front = (*head)->rear = temp;
    } else {
        (*head)->rear->next = temp;
        (*head)->rear = temp;
    }
    (*head)->size++;
}

int removeItem(Items **head){
    if((*head)->front == NULL){
        return -1;
    }
    Node *temp = (*head)->front;
    (*head)->front = (*head)->front->next;
    if((*head)->front == NULL){
        (*head)->rear = NULL;
    }
    int item = temp->item;
    delete temp;
    (*head)->size--;
    return item;
}

mutex mtx;
condition_variable cv;
Items *head = create_items();

void producer(int id){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 200);

    while(true){
        int newItem = dis(gen);
        {
            unique_lock<mutex> lck(mtx);
            if(head->size < MAX_ITEMS){
                insertItem(&head, newItem);
                cout << "Producer " << id << " produced item " << newItem << endl;
                cv.notify_all();
            }
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void consumer(int id){
    while(true){
        {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, []{ return head->size > 0; });
            int item = removeItem(&head);
            cout << "Consumer " << id << " consumed item " << item << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main(void){
    int numProducers;
    int numConsumers;

    cout << "Enter the number of producers: ";
    cin >> numProducers;
    cout << "Enter the number of consumers: ";
    cin >> numConsumers;

    vector<thread> producers;

    for(int i = 0; i < numProducers; i++){
        producers.push_back(thread(producer, i));
    }

    vector<thread> consumers;
    for(int i = 0; i < numConsumers; i++){
        consumers.push_back(thread(consumer, i));
    }

    for(auto &p : producers){
        p.join();
    }

    for(auto &c : consumers){
        c.join();
    }

    return 0;
}

// To compile: g++ -std=c++11 main.cpp -o main -pthread