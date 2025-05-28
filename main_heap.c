#include "binary_tree2.h"
#include <stdio.h>
#include <stdlib.h>

void printList(int *a, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  Tree *tree = malloc(sizeof(Tree));
  int active = 1;
  char op;
  int num;

  while (active) {
    scanf(" %c", &op);

    switch (op) {
    case '+':
      scanf("%d", &num);
      printf("+ %d\n", num);
      heapInsert(tree, num);
      printf("## ");
      printList(tree->values, tree->nodes);
      break;
    case '-':
      printf("- %d\n", heapOut(tree));
      printf("## ");
      printList(tree->values, tree->nodes);
      break;
    default:
      active = 0;
      break;
    }
  }
  free(tree);
  return 0;
}
