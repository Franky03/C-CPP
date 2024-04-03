#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int top;
    int capacity;
    char *array;
} Stack;

int isEmpty(Stack *stack){
    return stack->top == -1; 
}

int isFull(Stack *stack){
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, char item){
    if(isFull(stack)){
        return;
    }
    stack->array[++stack->top] = item; // increment top and then insert item
}

char pop(Stack *stack){
    if(isEmpty(stack)){
        return '\0';
    }
    return stack->array[stack->top--]; // return top and then decrement top 
}

int verifyExpression(char *expression){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = 100;
    stack->array = (char *)malloc(stack->capacity * sizeof(char)); 

    for(int i = 0; expression[i] != '\0'; i++){
        char current = expression[i];
        
        if(current == '(' || current == '{' || current == '['){
            push(stack, current); // when character is an opening bracket, push it to the stack
            continue;
        } else if(current == ')' || current == '}' || current == ']'){
            char last = pop(stack); // when character is a closing bracket, pop the top element from the stack and compare it with the current character
            if((current == ')' && last != '(') || (current == '}' && last != '{') || (current == ']' && last != '[')){
                return 0;  // if the current character is a closing bracket and the top element is not the corresponding opening bracket, return 0
            }
        }
    }

    // if the stack is empty after the loop, return 1, otherwise return 0
    return isEmpty(stack) ? 1 : 0;
}

int main(void){
    char expression[200];
    fgets(expression, 200, stdin); // using fgets because when using scanf, it stops reading when it finds a space character

    expression[strcspn(expression, "\n")] = '\0'; // remove newline character from the string

    int result =  verifyExpression(expression); 

    if(result){
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }

    return 0;
}