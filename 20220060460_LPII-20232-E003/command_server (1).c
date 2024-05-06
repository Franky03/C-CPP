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
#define QTD_CLIENTS 5
#define STR_SIZE 6

typedef struct {
	int fd;
	int index;

} t_client_info;

/*

RNDNUM, RNDSTR, DATTIM

*/

int generate_random_number() {
	return rand() % 256;
}

char* generate_random_string() {
	char *str = malloc((STR_SIZE + 1) * (sizeof(char)));
	for (int i = 0; i < STR_SIZE; i++) {
		str[i] = 'A' + (rand() % 26);
	}
	str[STR_SIZE] = '\0';

	return str;
}

char* get_date_time() {
	time_t now;
	time(&now);
	return ctime(&now);
}

void* handle_client(void* p) {
	t_client_info* cli_info = (t_client_info*)p;

        char buffer_read[BUFFER_SIZE];
        char buffer_write[BUFFER_SIZE];

	printf("Handling client(%d): %d\n", cli_info->index, cli_info->fd);

	while(1) {
		recv(cli_info->fd, buffer_read, (size_t) sizeof(buffer_read),0);
		if (strncmp(buffer_read, "RNDNUM", STR_SIZE) == 0) {
			printf("[%d] RNDNUM\n", cli_info->index);

			int random_num = generate_random_number();
			sprintf(buffer_write, "%d\n", random_num);
		} else if (strncmp(buffer_read, "RNDSTR", STR_SIZE) == 0) {
			printf("[%d] RNDSTR\n", cli_info->index);

			char* random_str = generate_random_string();
			sprintf(buffer_write, "%s\n", random_str);
		} else if (strncmp(buffer_read, "DATTIM", STR_SIZE) == 0) {
			printf("[%d] DATTIM\n", cli_info->index);

			char* datetime = get_date_time();
			sprintf(buffer_write, "%s\n", datetime);
		} else if (strncmp(buffer_read, "EXITSR", STR_SIZE) == 0) {
			printf("[%d] EXITSR\n", cli_info->index);

			send(cli_info->fd, "GOODBYE!\n", 9, 0);

			close(cli_info->fd);

			return 0;

		} else {
			printf("[%d] INVALID COMMAND: %s\n", cli_info->index,
				buffer_read);

			strcpy(buffer_write, "INVALID COMMAND!\n");
		}

		send(cli_info->fd, buffer_write, strlen(buffer_write), 0);

		bzero(buffer_read, BUFFER_SIZE);
		bzero(buffer_write, BUFFER_SIZE);

	}
}

int main(void) {
	int server_fd, client_fd[QTD_CLIENTS];
	struct sockaddr_in server_sock_config;
	struct sockaddr_in client_sock_info[QTD_CLIENTS];
	t_client_info iclients[QTD_CLIENTS];

	pthread_t client_threads[QTD_CLIENTS];

	int client_sock_info_size = 0;
	int buffer_read_size = 0;

	int client_counter = 0;

	time_t t;

	srand(time(&t));

	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (server_fd == -1) {
		perror("socket() error!");
		exit(EXIT_FAILURE);
	}

	server_sock_config.sin_family = AF_INET;
	server_sock_config.sin_port = htons(PORT);
	server_sock_config.sin_addr.s_addr = INADDR_ANY;

	int bind_return = bind(server_fd,
				(struct sockaddr*) &server_sock_config,
				sizeof(server_sock_config));

	if (bind_return == -1) {
		perror("bind() error!");
		exit(EXIT_FAILURE);

	}

	int listen_return = listen(server_fd, BACKLOGSIZE);

	if (listen_return == -1) {
		perror("listen() error!");
		exit(EXIT_FAILURE);
	}

	printf("Aguardando conexoes na porta: %d\n", PORT);

	while(1) {
		client_fd[client_counter] = accept(server_fd,
			   (struct sockaddr*) &client_sock_info[client_counter],
			    &client_sock_info_size);


		if (client_fd[client_counter] == -1) {
			perror("accept() error!");
			exit(EXIT_FAILURE);
		}

		printf("Nova conexao recebida\n");

		iclients[client_counter].fd = client_fd[client_counter];
		iclients[client_counter].index = client_counter;

		pthread_create(&client_threads[client_counter],
				NULL,
				handle_client,
				(void*) &iclients[client_counter]);
		client_counter++;

	}

	close(server_fd);

	return 0;
}
