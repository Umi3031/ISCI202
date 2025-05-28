#include "binary_tree2.h"
#include <stdio.h>
#include <stdlib.h>

void add(Tree *tree, int value) {
    if (tree->nodes >= 100) return;
    tree->values[tree->nodes++] = value;
}

void heapifyUp(Tree *tree, int index) {
    if (index == 0) return;
    int parentIndex = (index - 1) / 2;
    if (tree->values[parentIndex] < tree->values[index]) {
        swap(&tree->values[parentIndex], &tree->values[index]);
        heapifyUp(tree, parentIndex);
    }
}

void heapifyDown(Tree *tree, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < tree->nodes && tree->values[leftChild] > tree->values[largest]) {
        largest = leftChild;
    }
    if (rightChild < tree->nodes && tree->values[rightChild] > tree->values[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(&tree->values[index], &tree->values[largest]);
        heapifyDown(tree, largest);
    }
}

void heapInsert(Tree *tree, int value) {
    if (tree->nodes >= 100) return;
    tree->values[tree->nodes] = value;
    heapifyUp(tree, tree->nodes);
    tree->nodes++;
}

int heapOut(Tree *tree) {
    if (tree->nodes == 0) return -1;
    int rootValue = tree->values[0];
    tree->values[0] = tree->values[--tree->nodes];
    heapifyDown(tree, 0);
    return rootValue;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
