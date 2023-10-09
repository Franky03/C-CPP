// executar o comando countone
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char* binaries_to_test[] = {"00000000", "00000001", "00000010", "00000011", "00000100", "11110101", "01010110", "00000111", "11111111"};

    for(int i = 0; i < 9; i++){
        char command[50];
            snprintf(command, sizeof(command), "./countone %s", binaries_to_test[i]);
            system(command);
    }

    return 0;

}