#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
  int *values;
  int max_size;
  int length;
} ArrayList;

/* Жагсаалтыг хэвлэх */
void printList(ArrayList *list);

/* Жагсаалтыг хоослох */
void makeEmpty(ArrayList *list);

/* Шинэ n хэмжээтэй хоосон ArrayList үүсгэх */
ArrayList *createList(int n);

/* ArrayList-н санах ойг чөлөөлж, устгах */
void deleteList(ArrayList *list);

/* n утгатай элементийг хайж, index-г буцаах (0 -> n-1)
 * байхгүй бол -1 */
int find(ArrayList *list, int n);

/* j-р элементийг олж, утгыг result заагчид олгох
 * амжилттай олсон бол 1 (true), амжилтгүй бол 0 (false) буцаана */
int findAt(ArrayList *list, int j, int *result);

/* x-ийг j байранд оруулах
 * 0-с бага бол 0, уртаас их бол төгсгөлд нь оруулна */
void insertAt(ArrayList *list, int x, int j);

/* x-ийг n утгын ард оруулах
 * амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAfter(ArrayList *list, int x, int n);

/* j-р элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeAt(ArrayList *list, int j);

/* n утгатай элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeValue(ArrayList *list, int n);
/* e;ement oruulakh funkts*/
void insertElement(ArrayList *list, int value);

#endif 
// ARRAY_LIST_H
