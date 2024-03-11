#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define NUM_LETTERS 26
#define ASCII_A 65
#define NUM_FILES 10
#define MAX_KEY_SIZE 4

char* encrypt(const char* str, int tamanho) {
    char* str_result = (char*) malloc(sizeof(char)*tamanho);
    for (int i = 0; i < tamanho; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int chave = str[i] - ASCII_A;
            str_result[i] = (str[i] - ASCII_A + chave) % NUM_LETTERS + ASCII_A;
        }
    }
    
    return str_result;
}

// Decrypts the password
void decrypt(const char* encrypted_key, FILE* output_file, int file_number){
    
    char key[MAX_KEY_SIZE + 1] = {'\0'};  // Initializes the string with '\0'
    char* actual_key = (char*) malloc(sizeof(char)*(MAX_KEY_SIZE+1)); 
    
    for(int i=0; i< NUM_LETTERS; ++i){
        key[0] = 'A' + i;
        for(int j=0; j< NUM_LETTERS; ++j){
            key[1] = 'A' + j;
            for(int k=0; k< NUM_LETTERS; ++k){
                key[2] = 'A' + k;
                for(int l=0; l< NUM_LETTERS; ++l){ // Tests all possible combinations of letters for the password
                    key[3] = 'A' + l;

                    // Ensures the string ends with '\0' to avoid issues with the strcmp function
                    // (if it ends with '\n', for example, the comparison fails)
                    key[MAX_KEY_SIZE] = '\0'; 
                    
                    // Encrypts the password and compares it with the encrypted password
                    actual_key = encrypt(key, MAX_KEY_SIZE);

                    if(strcmp(actual_key, encrypted_key) == 0){
                        
                        fprintf(output_file, "%s - %s\n", key, encrypted_key);
                        free(actual_key);
                        return;
                    }

                    free(actual_key);
                }
            }
        }
    }

}

int main(int argc, char* argv[]){
    FILE* files_with_keys[NUM_FILES]; // Array of pointers to the files with passwords
    FILE* output_file = fopen("./keys.txt", "w"); // Where the passwords will be saved
    if(output_file == NULL){
        perror("Error opening file");
        exit(1);
    }

    for(int i=0; i<NUM_FILES; ++i){
        char file_name[20];
        sprintf(file_name, "senhas/%d.txt", i);
        files_with_keys[i] = fopen(file_name, "r"); 
        if(files_with_keys[i] == NULL){
            perror("Error opening file");
            exit(1);
        }
    }


    for(int i=0; i<NUM_FILES; ++i){
        pid_t pid = fork(); // Creates a child process, one for each file 
        if(pid == -1){
            perror("Error creating process");
            exit(1);
        }
        else if(pid == 0){ // Each child process will decrypt the passwords from a different file, so, if pid == 0, it is a child process 

            char* line = NULL;
            size_t len = 0;
            ssize_t read;
            int count = 0;
            while((read = getline(&line, &len, files_with_keys[i])) != -1){ // Reads the passwords from the file 
                
                if(strlen(line) != MAX_KEY_SIZE){
                    line[MAX_KEY_SIZE] = '\0';
                } // Ensures the password has the correct size

                count++;
                decrypt(line, output_file, i); // Decrypts the password

            }

            printf("File %d has %d keys in process %d\n", i, count, getpid());
            
            // Frees the memory and closes the file
            free(line);
            fclose(files_with_keys[i]);
            fclose(output_file);
            exit(0);
        }
    }

    for(int i=0; i<NUM_FILES; ++i){
        wait(NULL); // Waits for all child processes to finish
    }

    fclose(output_file);
    
    printf("All keys found and saved in keys.txt\n");
    return 0;
}
