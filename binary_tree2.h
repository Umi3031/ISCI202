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


/* Хоёр хувьсагчийн утга солих */
void swap(int *, int *);

/*
 * Heap байгуулах
 * мод болон оруулах элементүүдийг агуулсан хүснэгт, хүснэгтийн хэмжээ
 */
void buildHeap(Tree *, int *, int size);

/*
 * Heapify Up
 * мод болон heapify up гүйцэтгэж эхлэх индекс
 */
void heapifyUp(Tree *, int index);

/*
 * Heapify Down
 * мод болон heapify down гүйцэтгэж эхлэх индекс
 */
void heapifyDown(Tree *, int index);

/*
 * Heap-д элемент оруулах
 * add()-с ялгаатай нь элементээ нэмчихээд, зөв байрлалд нь оруулна
 * мод болон оруулах утга
 */
void heapInsert(Tree *, int);

/*
 * Heap-с элемент гаргах
 * гарсан элементийн утгыг буцаана
 */
int heapOut(Tree *);

#endif // BINARY_TREE_H
