#ifndef LINKED_LIST_H
#define LINKED_LIST_H
 
typedef struct Node {
  int val;
  struct Node *next;
} Node;
 
/* Жагсаалтыг хэвлэх */
void printList(Node *head);
 
/* Жагсаалтыг хоослох */
void makeEmpty(Node **head);
 
/* n утгатай шинэ Node үүсгэж, буцаах */
Node *createNode(int n);
 
/* n утгатай элементийг хайж, эхний олдсон Node-г буцаана
* байхгүй бол null буцаана */
Node *findValue(Node *head, int n);
 
/* j-р элементийг олж буцаах
* амжилтгүй бол null буцаана */
Node *findAt(Node *head, int j);
 
/* n утгатай элементийг хайж, хэд дэх элемент гэдгийг буцаана
* байхгүй бол -1 */
int findIndex(Node *head, int n);
 
/* x-ийг шинэ Node үүсгэн j-р байранд оруулах
* 0-с бага бол 0, уртаас их бол төгсгөлд нь оруулна,
* амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAt(Node **head, int x, int j);
 
/* x-ийг n утгатай Node-н ард оруулах
* амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAfter(Node *head, int x, int n);
 
/* j-р элементийг устгах
* амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeAt(Node **head, int j);
 
/* n утгатай элементийг устгах
* амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeValue(Node **head, int n);
 
/* Жагсаалтын уртыг олж, буцаана */
int length(Node *);
 
#endif // LINKED_LIST_H
