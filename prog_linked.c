#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100;
    Node *head = NULL;
  
    insertAt(&head, 11, 0);
    insertAt(&head, 12, 1);
    insertAt(&head, 13, 2);   
    insertAt(&head, 14, 3);
    insertAt(&head, 15, 4);
    insertAt(&head, 17, 5);
    insertAt(&head, 18, 6);
    insertAt(&head, 19, 7);
    insertAt(&head, 20, 8);
    insertAt(&head, 10, 0);
    insertAt(&head, 16, 6);
  
    printf("\n[%d] > ", length(head));
    printList(head);
  
    printf("%u ", insertAfter(head, 30, 10));
    printf("%u ", insertAfter(head, 31, 13));
    printf("%u ", insertAfter(head, 32, 20));
    printf("%u ", insertAfter(head, 123, 2000));
  
    printf("\n[%d] > ", length(head));
    printList(head);
  
    printf("%u ", removeAt(&head, 10));
    printf("%u ", removeAt(&head, 0));
    printf("%u ", removeAt(&head, 0));
    printf("%u ", removeAt(&head, 9));
    printf("%u ", removeAt(&head, -1));
    printf("%u ", removeAt(&head, 1000));
  
    printf("\n[%d] > ", length(head));
    printList(head);
    printf("\n");
  
    printf("%u ", removeValue(&head, 30));
    printf("%u ", removeValue(&head, 11));
    printf("%u ", removeValue(&head, 32));
    printf("%u ", removeValue(&head, 31));
    printf("%u ", removeValue(&head, 111));
  
    printf("\n[%d] > ", length(head));
    printList(head);
    printf("\n");
  
    Node *result;
    result = findAt(head, 0);
    printf("(%d)%d ", result != NULL, result != NULL ? result->val : 0);
    result = findAt(head, length(head) - 1);
    printf("(%d)%d ", result != NULL, result != NULL ? result->val : 0);
    result = findAt(head, 3);
    printf("(%d)%d ", result != NULL, result != NULL ? result->val : 0);
    result = findAt(head, -1);
    printf("(%d)%d ", result != NULL, result != NULL ? result->val : 0);
    result = findAt(head, length(head));
    printf("(%d)%d ", result != NULL, result != NULL ? result->val : 0);
  
    printf("\n");
    printf("%d:%d ", 10, findIndex(head, 10));
    printf("%d:%d ", 12, findIndex(head, 12));
    printf("%d:%d ", 19, findIndex(head, 19));
    printf("%d:%d ", 15, findIndex(head, 15));
    printf("%d:%d ", 923, findIndex(head, 923));
  
    makeEmpty(&head);
  
    printf("\n[%d] > ", length(head));
    printList(head);
    printf("\n");

    //makeEmpty(&head);
    return 0;
  }
