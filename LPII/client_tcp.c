#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


#define PORT 9999


int main(){
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    while(1){
        //clear the terminal
        system("clear");
        memset(buffer, 0, sizeof(buffer));
        read(sockfd, buffer, 1024);
        if(strcmp(buffer, "Goodbye\n") == 0){
            printf("Server closed connection.\n");
            break;
        }
        printf("Server: %s", buffer);
        

        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}