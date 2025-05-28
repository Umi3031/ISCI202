#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
 
void enqueue(ArrayList *list, int n) {
    if (list == NULL || list->length >= list->max_size) return;
    list->values[list->length] = n;
    list->length++;
}

 
int dequeue(ArrayList *list) {
    if (list == NULL || list->length == 0) return -1;
    int frontValue = list->values[0];
    removeAt(list, 0);
    return frontValue;
}

 
int main() {
  ArrayList *list = createList(100);
 
  int running = 1;
  int n;
  char op;
 
  while (running == 1) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d", &n);
      enqueue(list, n);
      break;
    case '-':
      printf("%d\n", dequeue(list));
      break;
    default:
      running = 0;
      break;
    }
    printf("[%d] > ", list->length);
    printList(list);
    printf("\n");
  }
 
  deleteList(list);
  free(list);
  return 0;
}
