#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct {
  int values[100];
  int nodes;
} Tree;

/* Модонд элемент нэмэх */
void add(Tree *, int);

/* Pre-order traversal */
void preorder(Tree *, int);

/* In-order traversal */
void inorder(Tree *, int);

/* Post-order traversal */
void postorder(Tree *, int);

/* Модны өндөр олох
 * Дамжуулсан элементээс эхэлж тооцно */
int height(Tree *, int);

/* Модны түвшин
 * Дамжуулсан элементээс эхэлж тооцно */
int level(Tree *, int);

/* Модноос элементийн утгаар байрлалыг олох (хүснэгтэн дэх дугаар) */
int nodeLoc(Tree *, int);

/* Модны эхний элементийн утга буцаах */
int root(Tree *);

/* Дамжуулсан элементийн эцэг нэгт элементийн индексийг олох */
int sibling(Tree *, int);

/* Дамжуулсан элементийн эцгийн индексийг олох */
int parent(Tree *, int);

/* Дамжуулсан элементийн бүх эцгийг хэвлэх */
void parents(Tree *, int);

#endif // BINARY_TREE_H
