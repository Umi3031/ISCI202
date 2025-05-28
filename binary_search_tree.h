#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
  int value;
  struct Node *parent;
  struct Node *left;
  struct Node *right;
} Node;

// Pre-order traversal
void preorder(Node *);

// In-order traversal
void inorder(Node *);

// Post-order traversal
void postorder(Node *);

// int утгатай шинэ node үүсгэх
Node *newNode(int);

// Модонд элемент нэмэх
Node *insert(Node *, int);

// Модноос элемент утгаар нь хайж хасах
Node *removeValue(Node *, int);

// Модноос параметраар ирсэн node-г хасах
Node *removeNode(Node *);

// Модноос элемент хайх
Node *search(Node *, int);

// Модны элементийн тоо
int count(Node *);

// Модны өндөр
int height(Node *);

// Модны оройг олох
Node *findRoot(Node *);

// а node-г b node-р солих
void replace(Node *a, Node *b);

// Модны хамгийн их элемент
Node *bstMax(Node *);

// Модны хамгийн бага элемент
Node *bstMin(Node *);

#endif // BINARY_SEARCH_TREE_H
