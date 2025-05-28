#include "binary_tree.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Tree *tree = malloc(sizeof(Tree));

  for (int i = 1; i < 17; i++) {
    add(tree, i * 10);
  }

  printf("Root: %d\n", root(tree));

  printf("Print: ");
  for (int i = 0; i < tree->nodes; i++) {
    printf("%d ", tree->values[i]);
  }
  printf("\n");

  printf("Pre-Order: ");
  preorder(tree, root(tree));
  printf("\n");
  printf("In-Order: ");
  inorder(tree, root(tree));
  printf("\n");
  printf("Post-Order: ");
  postorder(tree, root(tree));
  printf("\n");

  int search_val = 90;
  int si = sibling(tree, search_val);
  printf("Sibling (%d): %d %d\n", search_val, si,
         si >= 0 ? tree->values[si] : -1);
  search_val = 60;
  si = sibling(tree, search_val);
  printf("Sibling (%d): %d %d\n", search_val, si,
         si >= 0 ? tree->values[si] : -1);
  search_val = 150;
  si = sibling(tree, search_val);
  printf("Sibling (%d): %d %d\n", search_val, si,
         si >= 0 ? tree->values[si] : -1);
  search_val = 10;
  si = sibling(tree, search_val);
  printf("Sibling (%d): %d %d\n", search_val, si,
         si >= 0 ? tree->values[si] : -1);
  search_val = 160;
  si = sibling(tree, search_val);
  printf("Sibling (%d): %d %d\n", search_val, si,
         si >= 0 ? tree->values[si] : -1);

  printf("Height: %d\n", height(tree, root(tree)));
  printf("Level: %d\n", level(tree, root(tree)));
  printf("Height (110): %d\n", height(tree, 110));
  printf("Level (110): %d\n", level(tree, 110));
  printf("Height (40): %d\n", height(tree, 40));
  printf("Level (40): %d\n", level(tree, 40));
  printf("Height (160): %d\n", height(tree, 160));
  printf("Level (160): %d\n", level(tree, 160));

  printf("Parent (10): %d %d\n", parent(tree, 10),
         parent(tree, 10) > 0 ? tree->values[parent(tree, 10)] : -1);
  printf("Parent (70): %d %d\n", parent(tree, 70),
         parent(tree, 70) > 0 ? tree->values[parent(tree, 70)] : -1);

  printf("Parents (160): ");
  parents(tree, 160);
  printf("\n");
  printf("Parents (130): ");
  parents(tree, 130);
  printf("\n");
  printf("Parents (10): ");
  parents(tree, 10);
  printf("\n");

  free(tree);
  return 0;
}
