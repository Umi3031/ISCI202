#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
// element oruulakh
void insertElement(ArrayList *list, int value) {
    if (list==NULL || list->length>=list->max_size) return;
    list->values[list->length]=value;
    list->length++;
}

// Жагсаалтын бүх элементийг хэвлэх
void printList(ArrayList *list) {
    for (int i=0; i<list->length; i++) {
        printf("%d ", list->values[i]);
    }
    printf("\n");
}

// Жагсаалтыг хоослох
void makeEmpty(ArrayList *list) {
    if (list==NULL) return;
    list->length=0;
}

// n хэмжээтэй хоосон ArrayList үүсгэх
ArrayList *createList(int n) {
    if (n<=0) return NULL;
    
    ArrayList*list=(ArrayList*)malloc(sizeof(ArrayList));
    if (list==NULL) return NULL; // Sanakh oin khuviarlalt NULL butsaana

    list->values=(int*)malloc(n*sizeof(int));
    if (list->values==NULL) {
        return NULL;
    }

    list->max_size=n;
    list->length=0;

    return list;
}

// ArrayList-ийн санах ойг чөлөөлж, устгах
void deleteList(ArrayList *list) {
    if (list==NULL) return;
    
    free(list->values);
}

// n утгатай элементийг хайх
int find(ArrayList *list, int n) {
    if (list==NULL) return -1;

    for (int i=0; i<list->length; i++) {
        if (list->values[i]==n) {
            return i;
        }
    }
    return -1;
}

// j-р индекст байгаа утгыг олох
int findAt(ArrayList *list, int j, int *result) {
    if (list==NULL || j<0 || j>=list->length) return 0;

    *result=list->values[j];
    return 1;
}

// x утгыг j индекст оруулах
void insertAt(ArrayList *list, int x, int j) {
    if (list==NULL || list->length>=list->max_size) return;

    if (j<0) j=0;
    if (j>list->length) j=list->length;

    // Элементийн байрлалыг нэг ухраах
    for (int i=list->length; i>j; i--) {
        list->values[i]=list->values[i-1];
    }

    list->values[j]=x;
    list->length++;
}

// x-ийг n утгын ард оруулах
int insertAfter(ArrayList *list, int x, int n) {
    if (list==NULL || list->length>=list->max_size) return 0;

    int index=find(list, n);
    if (index==-1) return 0;

    insertAt(list, x, index + 1);
    return 1;
}

// j-р индекст байгаа элементийг устгах
int removeAt(ArrayList *list, int j) {
    if (list==NULL || j<0 || j>=list->length) return 0;

    // Элементийн байрлалыг урагш шилжүүлэх
    for (int i=j; i<list->length-1; i++) {
        list->values[i] = list->values[i + 1];
    }

    list->length--;
    return 1;
}

// n утгатай элементийг устгах
int removeValue(ArrayList *list, int n) {
    int index=find(list, n);
    if (index==-1) return 0;

    return removeAt(list, index);
}
