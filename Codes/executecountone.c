// executar o comando countone
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char* binaries_to_test[] = {"0000", "0001", "0010", "1111", "0100", "0101", "0110", "0111"};

    for(int i = 0; i < 8; i++){
        char command[50];
            snprintf(command, sizeof(command), "./countone %s", binaries_to_test[i]);
            system(command);
    }

    return 0;

}