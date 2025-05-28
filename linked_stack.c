#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void push(Node **head, int n) {
    Node *newNode = createNode(n);
    if (newNode == NULL) return;

    newNode->next = *head;
    *head = newNode;
}

int pop(Node **head) {
    if (*head == NULL) return -1;

    Node *temp = *head;
    int value = temp->val;
    *head = temp->next;

    free(temp);
    return value;
}

int main() {
  Node *head = NULL;

  int running = 1;
  int n;
  char op;

  while (running == 1) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d", &n);
      push(&head, n);
      break;
    case '-':
      printf("%d\n", pop(&head));
      break;
    default:
      running = 0;
      break;
    }
    printf("[%d] > ", length(head));
    printList(head);
    printf("\n");
  }

  makeEmpty(&head);
  return 0;
}
