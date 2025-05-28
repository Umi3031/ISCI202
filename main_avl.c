#include "binary_search_tree2.h"
#include <stdio.h>

void debugPrint(char op, int num, Node *root) {
  printf("# %c%d", op, num);
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
      // AVL мод тул insertAVL-г дуудаж байгааг анхаарна уу
      root = insertAVL(root, num);
      debugPrint(op, num, root);
      // DO NOT EDIT: BEGIN
      inorder(root);
      printf("\t(");
      if(root!=NULL) printf("root: %d ", root->value);
      printf("height: %d)", height(root));
      printf("\n");
      // DO NOT EDIT: END
      break;
    case '-':
      scanf("%d", &num);
      // AVL мод тул removeAVLValue-г дуудаж байгааг анхаарна уу
      root = removeAVLValue(root, num);
      debugPrint(op, num, root);
      // DO NOT EDIT: BEGIN
      inorder(root);
      printf("\t(");
      if(root!=NULL) printf("root: %d ", root->value);
      printf("height: %d)", height(root));
      printf("\n");
      // DO NOT EDIT: END
      break;
    default:
      active = 0;
      break;
    }
  }

  return 0;
}
