#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int height;
} Node;
Node* insertAVL(Node* root, int value);
Node* removeAVLValue(Node* root, int value);
Node* newNode(int value);
Node* insert(Node* root, int value);
Node* search(Node* root, int value);
Node* removeValue(Node* root, int value);
Node* bstMin(Node* node);
Node* bstMax(Node* node);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
int count(Node* root);
int height(Node* root);
int balanceFactor(Node* node);
Node* rotateLeft(Node* x);
Node* rotateRight(Node* x);

#endif
