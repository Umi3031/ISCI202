#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
 
void push(ArrayList *list, int n) {
    insertElement(list, n);
}

 
int pop(ArrayList *list) {
    if (list == NULL || list->length == 0) return -1;
    int last_value = list->values[list->length - 1];
    list->length--;
    return last_value;
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
      push(list, n);
      break;
    case '-':
      printf("%d\n", pop(list));
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
