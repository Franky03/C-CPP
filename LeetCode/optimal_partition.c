#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int set[26];
} HashSet;

void initializeHashSet(HashSet *hs){
    memset(hs->set, 0, sizeof(hs->set)); // set all the elements of the set to 0
}

void addElement(HashSet *hs, char c){
    hs->set[c - 'a'] = 1; // set the value of the character to 1 in the set to indicate that it is present
}

int contains(HashSet *hs, char c){
    return hs->set[c - 'a']; // return 1 if the character is present in the set, 0 otherwise    
}

int countSubstrings(char *s){
    int index = 0;
    int count = 0;
    HashSet hs;
    initializeHashSet(&hs);

    while(index < strlen(s)){
        if(contains(&hs, s[index])){
            count++;
            initializeHashSet(&hs);
        }
        
        addElement(&hs, s[index]);
        index++;
    }

    return count + 1;
    
}

int main(void){
    char s[MAX];
    printf("Enter the string: ");
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0; // remove the newline character from the string
    printf("The number of distinct substrings of the string is: %d\n", countSubstrings(s));

    return 0;
}