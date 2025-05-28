#include <iostream>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Student {
  string id;
  string fname;
  string lname;
  string major;
  int level;
  float gpa;
  struct Student *next = NULL;
};

// Student хэвлэх
void printStudent(Student *);

// Жагсаалтыг хэвлэх
void printList(Student *);

// Жагсаалтыг хоослох
void makeEmpty(Student *);

// Student-г id-р хайх, олдоогүй бол NULL
struct Student *find(Student *, string id);

// Student-г id-р хайж, дугаарыг олох, олдоогүй бол -1
int findI(Student *, string id);

// i-р элементийг устгах
void remove(Student **, int i);

// Student-г id-р устгах
void removeById(Student **, string id);

// Жагсаалтаас k-р Student-г олох, олдоогүй бол NULL
struct Student *findKth(Student *, int k);

// k-р элементийн дугаарыг олох, олдоогүй бол -1
int findKthI(Student *, int k);

// Жагсаалтын уртыг олох
int length(Student *);

// Hash Function
int hashf(string);

// Hash хүснэгтэд оруулах
void hashInsert(Student **, Student *);

// Hash хүснэгтэд оруулах
void hashInsert(Student **, string id, string fname, string lname, string major,
                int level, float gpa);

// Hash хүснэгт хэвлэх
void printHash(Student **, int);

// Hash хүснэгтээс id-р хайх, олдоогүй бол NULL
Student *search(Student **, string id);

// Hash хүснэгтээс id-р устгах
void hashRemove(Student **, string id);

#endif // HASHTABLE_H
