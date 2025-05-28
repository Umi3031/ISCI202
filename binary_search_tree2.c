#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree2.h"

Node *newNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = node->parent = NULL;
    return node;
}

Node *insert(Node *root, int value) {
    if (!root) return newNode(value);
    if (value < root->value) {
        Node *leftChild = insert(root->left, value);
        root->left = leftChild;
        leftChild->parent = root;
    } else {
        Node *rightChild = insert(root->right, value);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

Node *search(Node *root, int value) {
    if (!root || root->value == value) return root;
    if (value < root->value) return search(root->left, value);
    else return search(root->right, value);
}

Node *bstMin(Node *node) {
    while (node && node->left) node = node->left;
    return node;
}

Node *bstMax(Node *node) {
    while (node && node->right) node = node->right;
    return node;
}

void replace(Node *a, Node *b) {
    if (!a->parent) return;
    if (a == a->parent->left) a->parent->left = b;
    else a->parent->right = b;
    if (b) b->parent = a->parent;
}

Node *removeNode(Node *node) {
    if (!node->left && !node->right) {
        replace(node, NULL);
        free(node);
        return NULL;
    }
    if (!node->left) {
        replace(node, node->right);
        free(node);
        return node->right;
    }
    if (!node->right) {
        replace(node, node->left);
        free(node);
        return node->left;
    }
    Node *min = bstMin(node->right);
    node->value = min->value;
    node->right = removeValue(node->right, min->value);
    return node;
}

Node *removeValue(Node *root, int value) {
    if (!root) return NULL;
    if (value < root->value) root->left = removeValue(root->left, value);
    else if (value > root->value) root->right = removeValue(root->right, value);
    else root = removeNode(root);
    return root;
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

int count(Node *root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}

int height(Node *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

Node *findRoot(Node *node) {
    while (node && node->parent) node = node->parent;
    return node;
}

// ----------- AVL SECTION BELOW ------------

int balanceFactor(Node *node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

Node *rotateLeft(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->left = x;
    y->parent = x->parent;
    x->parent = y;
    return y;
}

Node *rotateRight(Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->right = y;
    x->parent = y->parent;
    y->parent = x;
    return x;
}

Node *rotateLeftRight(Node *node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node *rotateRightLeft(Node *node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Node *rotate(Node *node) {
    int bf = balanceFactor(node);
    if (bf > 1) {
        if (balanceFactor(node->left) >= 0)
            return rotateRight(node);
        else
            return rotateLeftRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->right) <= 0)
            return rotateLeft(node);
        else
            return rotateRightLeft(node);
    }
    return node;
}

Node *insertAVL(Node *node, int value) {
    if (!node) return newNode(value);
    if (value < node->value) {
        node->left = insertAVL(node->left, value);
        if (node->left) node->left->parent = node;
    } else {
        node->right = insertAVL(node->right, value);
        if (node->right) node->right->parent = node;
    }
    return rotate(node);
}

Node *removeAVL(Node *node) {
    if (!node) return NULL;
    if (!node->left && !node->right) {
        free(node);
        return NULL;
    }
    if (!node->left || !node->right) {
        Node *temp = node->left ? node->left : node->right;
        temp->parent = node->parent;
        free(node);
        return temp;
    }
    Node *min = bstMin(node->right);
    node->value = min->value;
    node->right = removeAVLValue(node->right, min->value);
    return rotate(node);
}

Node *removeAVLValue(Node *root, int value) {
    if (!root) return NULL;
    if (value < root->value) root->left = removeAVLValue(root->left, value);
    else if (value > root->value) root->right = removeAVLValue(root->right, value);
    else return removeAVL(root);
    return rotate(root);
}
