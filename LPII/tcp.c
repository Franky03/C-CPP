#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#include <unistd.h>

#define PORT 9999
#define BACKLOG 5

char* handle_random_number(){
    srand(time(NULL));
    int random_number = rand() % 1000 + 1;
    char* response = (char*) malloc(20 * sizeof(char));
    sprintf(response, "%d", random_number);
    return response;
}

char* handle_datetime(){
    time_t now;
    struct tm* local_time;
    char* response = (char*) malloc(50 * sizeof(char));
    time(&now);
    local_time = localtime(&now);
    strftime(response, 50, "%Y-%m-%d %H:%M:%S", local_time);
    return response;
}

char* handle_random_string(){
    char* response = (char*) malloc(50 * sizeof(char));
    // create a random string
    for(int i = 0; i < 19; i++){
        response[i] = (rand() % 26) + 97;
    }
    response[19] = '\0';
    return response;
}

void* client_handler(void *arg){
    int client_fd = *((int*) arg);
    char buffer[1024] = {0};
    const char* response;

    while (1) {
        send(client_fd, "\n1. Random Number\n2. Datetime\n3. Random String\n4. Sair\n", strlen("\n1. Random Number\n2. Datetime\n3. Random String\n4. Sair\n"), 0);
        read(client_fd, buffer, 1024);

        // remove \n from buffer
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "1") == 0) {
            response = handle_random_number();
        } else if (strcmp(buffer, "2") == 0) {
            response = handle_datetime();
        } else if (strcmp(buffer, "3") == 0) {
            response = handle_random_string();
        } else if (strcmp(buffer, "4") == 0) {
            response = "Goodbye\n";
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            break;
        } else {
            response = "Invalid option";
        }

        send(client_fd, response, strlen(response), 0);
    }

    pthread_exit(NULL);
}

int main() {
    int server_fd;
    struct sockaddr_in server;
    int addr_len = sizeof(struct sockaddr_in);

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while(1){
        int client_fd;
        struct sockaddr_in client;
        
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client, (socklen_t *)&addr_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_fd) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }

        pthread_detach(thread_id);

    }

    close(server_fd);
    return 0;

}
