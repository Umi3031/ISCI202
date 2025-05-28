#include <stdlib.h>
#include "binary_search_tree.h"

// Шинэ node үүсгэх
Node *newNode(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->parent = node->left = node->right = NULL;
  return node;
}

// Pre-order traversal
void preorder(Node *root) {
  if (!root) return;
  printf("%d ", root->value);
  preorder(root->left);
  preorder(root->right);
}

// In-order traversal
void inorder(Node *root) {
  if (!root) return;
  inorder(root->left);
  printf("%d ", root->value);
  inorder(root->right);
}

// Post-order traversal
void postorder(Node *root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->value);
}

// Insert хийх
Node *insert(Node *root, int value) {
  if (root == NULL) {
    return newNode(value);
  }

  if (value < root->value) {
    Node *leftChild = insert(root->left, value);
    root->left = leftChild;
    leftChild->parent = root;
  } else if (value > root->value) {
    Node *rightChild = insert(root->right, value);
    root->right = rightChild;
    rightChild->parent = root;
  }

  return root;
}

// Min утгатай node
Node *bstMin(Node *node) {
  while (node && node->left)
    node = node->left;
  return node;
}

// Max утгатай node
Node *bstMax(Node *node) {
  while (node && node->right)
    node = node->right;
  return node;
}

// Node хайх
Node *search(Node *root, int value) {
  if (!root || root->value == value) return root;
  if (value < root->value)
    return search(root->left, value);
  else
    return search(root->right, value);
}

// Node-г солих
void replace(Node *a, Node *b) {
  if (a->parent) {
    if (a == a->parent->left)
      a->parent->left = b;
    else
      a->parent->right = b;
  }
  if (b)
    b->parent = a->parent;
}

// Node устгах
Node *removeNode(Node *node) {
  if (!node) return NULL;

  if (!node->left && !node->right) {
    if (node->parent)
      replace(node, NULL);
    free(node);
    return NULL;
  }

  if (!node->left) {
    Node *child = node->right;
    replace(node, child);
    free(node);
    return child;
  }

  if (!node->right) {
    Node *child = node->left;
    replace(node, child);
    free(node);
    return child;
  }

  Node *successor = bstMin(node->right);
  node->value = successor->value;
  removeNode(successor);
  return node;
}

// Утгаар node устгах
Node *removeValue(Node *root, int value) {
  Node *node = search(root, value);
  if (!node) return root;

  if (node == root) {
    Node dummy;
    dummy.left = root;
    root->parent = &dummy;
    removeNode(root);
    root = dummy.left;
    if (root)
      root->parent = NULL;
  } else {
    removeNode(node);
  }

  return root;
}

// Тоо тоолох
int count(Node *root) {
  if (!root) return 0;
  return 1 + count(root->left) + count(root->right);
}

// Өндөр олох
int height(Node *root) {
  if (!root) return -1;
  int hl = height(root->left);
  int hr = height(root->right);
  return (hl > hr ? hl : hr) + 1;
}

// Root олох
Node *findRoot(Node *node) {
  while (node && node->parent)
    node = node->parent;
  return node;
}
