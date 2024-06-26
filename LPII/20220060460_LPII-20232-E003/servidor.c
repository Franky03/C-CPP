#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>

#define PORT 9999
#define BACKLOGSIZE 5
#define BUFFER_SIZE 1024
#define QTD_CLIENTS 10
#define STR_SIZE 4
#define FILENAME "messages.txt"

typedef struct {
	int fd;
	int index;
	int halt_received; // Indica se o cliente enviou "HALT"
} t_client_info;

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;
int halt_counter = 0;

void write_to_file(const char* message){
	FILE* file = fopen(FILENAME, "a");
	if (file == NULL) {
		perror("fopen() error!");
		exit(EXIT_FAILURE);
	}
	fputs(message, file);
	fclose(file);	
}

void* handle_client(void* p) {
	t_client_info* cli_info = (t_client_info*)p;

        char buffer_read[BUFFER_SIZE];
        char buffer_write[BUFFER_SIZE];

	printf("Handling client(%d): %d\n", cli_info->index, cli_info->fd);

	while(1) {
		recv(cli_info->fd, buffer_read, (size_t) sizeof(buffer_read),0);
		pthread_mutex_lock(&file_mutex);
		if (strncmp(buffer_read, "SHOW", STR_SIZE) == 0) {
			printf("[%d] SHOW\n", cli_info->index);
			FILE* file = fopen(FILENAME, "r");
			if (file == NULL) {
				strcpy(buffer_write, "Error opening file\n");
			}
			fseek(file, 0, SEEK_END);
			long fsize = ftell(file); // get the file size
			fseek(file, 0, SEEK_SET);
			fread(buffer_write, fsize, 1, file); // read the file
			fclose(file);
			
		} else if (strncmp(buffer_read, "HALT", STR_SIZE) == 0) {
			printf("[%d] HALT\n", cli_info->index);

			send(cli_info->fd, "GOODBYE!\n", 9, 0);
			close(cli_info->fd);
			cli_info->halt_received = 1; // Marca que o cliente enviou "HALT"
            halt_counter++;
            printf("HALT counter: %d\n", halt_counter);
            if (halt_counter >= 5){
                printf("Closing server because 5 clients sent HALT\n");
                pthread_mutex_unlock(&file_mutex);
                // fecha todos os clientes e o servidor
                for (int i = 0; i < QTD_CLIENTS; i++) {
                    if (cli_info->halt_received == 0) {
                        close(cli_info->fd);
                    }
                }
                exit(EXIT_SUCCESS);
            }
            pthread_mutex_unlock(&file_mutex);
			return NULL;

		} else {
			printf("[%d] Writing to file: %s", cli_info->index, buffer_read);
            write_to_file(buffer_read);
            strcpy(buffer_write, "Message received and written to file\n");
            
		}
		pthread_mutex_unlock(&file_mutex);
		send(cli_info->fd, buffer_write, strlen(buffer_write), 0);

		memset(buffer_read, 0, sizeof(buffer_read));
		memset(buffer_write, 0, sizeof(buffer_write));
	}
}

int main(void) {
    int server_fd, client_fd[QTD_CLIENTS];
    struct sockaddr_in server_sock_config;
    struct sockaddr_in client_sock_info;
    t_client_info iclients[QTD_CLIENTS];
    pthread_t client_threads[QTD_CLIENTS];
	socklen_t client_sock_info_size = sizeof(client_sock_info);

    srand(time(NULL));

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket() error!");
        exit(EXIT_FAILURE);
    }

    server_sock_config.sin_family = AF_INET;
    server_sock_config.sin_port = htons(PORT);
    server_sock_config.sin_addr.s_addr = INADDR_ANY;

    int bind_return = bind(server_fd, (struct sockaddr*) &server_sock_config, sizeof(server_sock_config));
    if (bind_return == -1) {
        perror("bind() error!");
        exit(EXIT_FAILURE);
    }

    int listen_return = listen(server_fd, BACKLOGSIZE);
    if (listen_return == -1) {
        perror("listen() error!");
        exit(EXIT_FAILURE);
    }

    printf("Holding for connections on port %d\n", PORT);

    int client_counter = 0;

    while (1) {
        client_fd[client_counter] = accept(server_fd, (struct sockaddr*) &client_sock_info, &client_sock_info_size);
        if (client_fd[client_counter] == -1) {
            perror("accept() error!");
            exit(EXIT_FAILURE);
        }

        printf("New connection received !\n");

        iclients[client_counter].fd = client_fd[client_counter];
        iclients[client_counter].index = client_counter;
		iclients[client_counter].halt_received = 0;

        pthread_create(&client_threads[client_counter], NULL, handle_client, (void*) &iclients[client_counter]);

        client_counter++;
        if (client_counter >= QTD_CLIENTS) {
            printf("Max clients reached\n");
            break;
        }
    }

    close(server_fd);
    pthread_mutex_destroy(&file_mutex);
    return 0;
}