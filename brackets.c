#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "linked_list.h"
#include "linked_stack.h"

// Хаалтын хослолыг шалгах функц
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Хаалтын зөв эсэхийг шалгах функц
bool isBalanced(const char* expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) {
                freeStack(&stack);
                return false;
            }
        }
    }

    bool balanced = isEmpty(&stack);
    freeStack(&stack);
    return balanced;
}

// Гол програм
int main() {
    char expression[100];
    scanf("%s", expression);

     if (isBalanced(expression)) {
        printf("ALDAAGUI\n");
    } else {
        printf("ALDAATAI\n");
    }

    return 0;
}
