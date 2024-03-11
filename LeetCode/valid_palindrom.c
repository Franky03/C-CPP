#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* onlyAlphaNum(char *s){
    int i = 0, j = 0;
    char *newStr = (char *)malloc(strlen(s)+1);

    while(i<strlen(s)){
        if(isalnum(s[i])){
            newStr[j] = tolower(s[i]);
            j++;    
        }
        i++;
    }   

    newStr[j] = '\0';

    return newStr;
}

int isPalindrome(char *s){
    int i = 0, j = strlen(s)-1; 

    while(i<j){
        while(i<j && !isalnum(s[i])) i++; 
        while(i<j && !isalnum(s[j])) j--;

        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }

        i++;
        j--;
    }
    return true;
}

int main() {

    char str[] = "A man, a plan, a canal: Panama";
    printf("%d\n", isPalindrome(str));

    


    return 0;
}