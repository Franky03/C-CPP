#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE* arch;
    char ch;

    // Opening file in reading mode
    arch= fopen("arch.txt", "r");
    
    if(NULL== arch){
        printf("file cant be opened \n");
        return 1;
    }

    printf("content on this file: \n");
    // Printing what is written in file
    // character by character using loop.
    do
    {
        ch= fgetc(arch);
        printf("%c", ch);

        // Checking if character is not EOF.
        // If it is EOF stop eading.
        // EOF = End of Line

    } while (ch != EOF);
    
    //Closing file
    fclose(arch);

    return 0;
}