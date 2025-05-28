#include "binary_search_tree.h"
#include <stdio.h>

void debugPrint(char op, int num, Node *root) {
  printf("# +%d", num);
  if (root != NULL)
    printf(" root: %d", root->value);
  printf("\n");
}

int main() {
  Node *root = NULL;
  int active = 1;
  char op;
  int num;

  while (active) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d", &num);
      root = insert(root, num);
      debugPrint(op, num, root);
      inorder(root);
      printf("\n");
      break;
    case '-':
      scanf("%d", &num);
      root = removeValue(root, num);
      debugPrint(op, num, root);
      inorder(root);
      printf("\n");
      break;
    default:
      active = 0;
      break;
    }
  }

  return 0;
}
