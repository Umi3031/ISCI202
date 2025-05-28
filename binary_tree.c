#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void add(Tree *tree, int value) {
    if (tree->nodes < 100) {
        tree->values[tree->nodes++] = value;
    }
}

/* Pre-order traversal */
void preorder(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index == -1) return;
    printf("%d ", tree->values[index]);
    preorder(tree, tree->values[2 * index + 1]); // Left
    preorder(tree, tree->values[2 * index + 2]); // Right
}

/* In-order traversal */
void inorder(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index == -1) return;
    inorder(tree, tree->values[2 * index + 1]);
    printf("%d ", tree->values[index]);
    inorder(tree, tree->values[2 * index + 2]);
}

/* Post-order traversal */
void postorder(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index == -1) return;
    postorder(tree, tree->values[2 * index + 1]);
    postorder(tree, tree->values[2 * index + 2]);
    printf("%d ", tree->values[index]);
}

/* Өндөр олох */
int height(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index == -1) return 0;
    int leftHeight = height(tree, tree->values[2 * index + 1]);
    int rightHeight = height(tree, tree->values[2 * index + 2]);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

/* Түвшин олох */
int level(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index == -1) return -1;
    int count = 0;
    while (index > 0) {
        index = (index - 1) / 2;
        count++;
    }
    return count;
}

/* Элементийн байршил олох */
int nodeLoc(Tree *tree, int value) {
    for (int i = 0; i < tree->nodes; i++) {
        if (tree->values[i] == value) return i;
    }
    return -1;
}

/* Root олох */
int root(Tree *tree) {
    return tree->nodes > 0 ? tree->values[0] : -1;
}

/* Сиблин олгох */
int sibling(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index <= 0) return -1; 

    int parentIndex = (index - 1) / 2; 
    int leftChild = 2 * parentIndex + 1;
    int rightChild = 2 * parentIndex + 2;

    if (leftChild < tree->nodes && leftChild == index) {
        return (rightChild < tree->nodes) ? rightChild : -1;
    } else if (rightChild < tree->nodes && rightChild == index) {
        return (leftChild < tree->nodes) ? leftChild : -1;
    }
    
    return -1;
}

/* Эцэг элемент олох */
int parent(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    if (index <= 0) return -1;
    return (index - 1) / 2;
}

/* Бүх эцэг элементийн жагсаалт хэвлэх */
void parents(Tree *tree, int value) {
    int index = nodeLoc(tree, value);
    while (index > 0) {
        printf("%d ", tree->values[(index - 1) / 2]); 
        index = (index - 1) / 2;
    }
    printf("\n");
}
