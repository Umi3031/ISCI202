#include "array_list.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n= 100;
  ArrayList *list = createList(n);

  insertAt(list, 11, 0);
  insertAt(list, 12, 1);
  insertAt(list, 13, 2);
  insertAt(list, 14, 3);
  insertAt(list, 15, 4);
  insertAt(list, 17, 5);
  insertAt(list, 18, 6);
  insertAt(list, 19, 7);
  insertAt(list, 20, 8);
  insertAt(list, 10, 0);
  insertAt(list, 16, 6);

  printf("\n[%d] > ",list->length);
  printList(list);
  printf("\n");

  printf("%u ", insertAfter(list, 30, 10));
  printf("%u ", insertAfter(list, 31, 13));
  printf("%u ", insertAfter(list, 32, 20));
  printf("%u ", insertAfter(list, 123, 2000));

  printf("\n[%d] > ",list->length);
  printList(list);
  printf("\n");

  printf("%u ", removeAt(list, 10));
  printf("%u ", removeAt(list, 0));
  printf("%u ", removeAt(list, 0));
  printf("%u ", removeAt(list, 9));
  printf("%u ", removeAt(list, -1));
  printf("%u ", removeAt(list, 1000));

  printf("\n[%d] > ",list->length);
  printList(list);
  printf("\n");

  printf("%u ", removeValue(list, 30));
  printf("%u ", removeValue(list, 11));
  printf("%u ", removeValue(list, 32));
  printf("%u ", removeValue(list, 31));
  printf("%u ", removeValue(list, 111));

  printf("\n[%d] > ",list->length);
  printList(list);
  printf("\n");

  int result;
  printf("(%d)", findAt(list, 0, &result));
  printf("%d ", result);
  printf("(%d)", findAt(list, list->length - 1, &result));
  printf("%d ", result);
  printf("(%d)", findAt(list, 3, &result));
  printf("%d ", result);
  printf("(%d)", findAt(list, -1, &result));
  printf("%d ", result);
  printf("(%d)", findAt(list, list->length, &result));
  printf("%d ", result);

  printf("\n");
  printf("%d:%d ", 10, find(list, 10));
  printf("%d:%d ", 12, find(list, 12));
  printf("%d:%d ", 19, find(list, 19));
  printf("%d:%d ", 15, find(list, 15));
  printf("%d:%d ", 923, find(list, 923));

  makeEmpty(list);

  printf("\n[%d] > ",list->length);
  printList(list);
  printf("\n");

  deleteList(list);
  free(list);
  return 0;
}
