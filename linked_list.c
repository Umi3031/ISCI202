#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
 
// TODO: array_list.h дотор тодорхойлсон функцуудыг хэрэгжүүлэх
 
void printList(Node *head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d  ", current->val);
        current=current->next;
    }
    printf("\n");
}
void makeEmpty(Node **head) {
    Node *current=*head;
    Node *temp;
    while (current!=NULL) {
        temp=current;
        current=current->next;
        free(temp);
    }
    *head=NULL;
}
Node *createNode(int n) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->val = n;
    newNode->next = NULL;
    return newNode;
}

Node *findValue(Node *head, int n) {
    Node *current = head;
    while (current != NULL) {
        if (current->val == n) return current;
        current = current->next;
    }
    return NULL;
}

Node *findAt(Node *head, int j) {
    int index = 0;
    Node *current = head;
    while (current != NULL) {
        if (index == j) return current;
        current = current->next;
        index++;
    }
    return NULL;
}

int findIndex(Node *head, int n) {
    int index = 0;
    Node *current = head;
    while (current != NULL) {
        if (current->val == n) return index;
        current = current->next;
        index++;
    }
    return -1;
}

int insertAt(Node **head, int x, int j) {
    Node *newNode = createNode(x);
    if (newNode == NULL) return 0;
    
    if (j <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return 1;
    }
    
    Node *current = *head;
    for (int i = 0; i < j - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return 1;
}

int insertAfter(Node *head, int x, int n) {
    Node *target = findValue(head, n);
    if (target == NULL) return 0;
    
    Node *newNode = createNode(x);
    if (newNode == NULL) return 0;
    
    newNode->next = target->next;
    target->next = newNode;
    return 1;
}

int removeAt(Node **head, int j) {
    if (*head == NULL) return 0;
    if (*head == NULL || j < 0) return 0;
    
    Node *current = *head;
    if (j == 0) {
        *head = current->next;
        free(current);
        return 1;
    }
    
    Node *prev = NULL;
    for (int i = 0; i < j && current != NULL; i++) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) return 0;
    
    prev->next = current->next;
    free(current);
    return 1;
}

int removeValue(Node **head, int n) {
    if (*head == NULL) return 0;
    
    Node *current = *head, *prev = NULL;
    while (current != NULL && current->val != n) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) return 0;
    
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return 1;
}

int length(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
