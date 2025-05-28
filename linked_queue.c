#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int enqueue(Node **head, int n) {
    Node *newNode = createNode(n);
    if (newNode == NULL) return 0;  // Санах ой олдоогүй үед

    if (*head == NULL) {  // Хэрэв жагсаалт хоосон байвал эхэнд нь нэмнэ
        *head = newNode;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL) {  // Жагсаалтын төгсгөл хүртэл явна
        current = current->next;
    }
    
    current->next = newNode;  // Шинэ Node-г төгсгөлд нь холбоно
    return 1;
}


int dequeue(Node **head) {
    if (*head == NULL) return -1;  // Хоосон жагсаалт бол -1 буцаана

    Node *temp = *head;
    int value = temp->val;  // Эхний элементийн утгыг хадгалах
    *head = temp->next;  // Жагсаалтын эхлэлийг дараагийн элемент болгох

    free(temp);  // Санах ойг чөлөөлөх
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
      enqueue(&head, n);
      break;
    case '-':
      printf("%d\n", dequeue(&head));
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
