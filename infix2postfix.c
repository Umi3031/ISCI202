#include "linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int infix2postfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char current = infix[i];
        
        if (isdigit(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            // Push '(' 
            push(&stack, current);
        } else if (current == ')') {
            // Pop  '(' 
            while (!isEmpty(&stack) && stack.top->data != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        } else {
            // Operator (+, -, *, /)
            while (!isEmpty(&stack) && precedence(stack.top->data) >= precedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }
        i++;
    }
    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0'; 
    freeStack(&stack);
    
    return j;
}
int evaluate_postfix(char *postfix, int len) {
    Stack stack;
    initStack(&stack);
    int i = 0;
    
    while (i < len) {
        char current = postfix[i];
        
        if (isdigit(current)) {
            push(&stack, current - '0');  
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            // Apply operator
            int result = 0;
            if (current == '+') {
                result = operand1 + operand2;
            } else if (current == '-') {
                result = operand1 - operand2;
            } else if (current == '*') {
                result = operand1 * operand2;
            } else if (current == '/') {
                result = operand1 / operand2;
            }
            
            push(&stack, result);
        }
        i++;
    }
    
    int finalResult = pop(&stack);
    freeStack(&stack);
    
    return finalResult;
}

int main() {
    char infix[100], postfix[100];
    
    scanf("%s", infix);
    
    int j = infix2postfix(infix, postfix);
    printf("### Infix to Postfix\n");
    for (int i = 0; i < j; i++) {
        printf("%c ", postfix[i]);
    }
    
    printf("\n### Evaluation:\n");
    printf("~ %s == %d\n", infix, evaluate_postfix(postfix, j));
    
    return 0;
}
