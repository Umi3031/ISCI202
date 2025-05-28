#include "hashtable.h"

void makeEmptyHashArray(Student **, int, int);

int main() {
  int hashSize = 10000;
  Student **hashTable = new Student *[hashSize];
  makeEmptyHashArray(hashTable, hashSize, 0);

  hashInsert(hashTable, "14B1DSS1375", "Bold", "Bat", "Information Technology",
             3, 3.0);
  hashInsert(hashTable, "13B1DSS3121", "Oyun", "Enkhbat", "Software Engineer",
             4, 3.7);
  hashInsert(hashTable, "16B1DSS0053", "Bat", "Bayaraa", "Electronic Engineer",
             1, 3.3);
  hashInsert(hashTable, "16B1DSS1732", "Itgel", "D.", "Information Technology",
             1, 3.2);
  hashInsert(hashTable, "17B1DSS1375", "Dulguun", "Bold", "Electronic Engineer",
             3, 3.1);
  hashInsert(hashTable, "15B1DSS2467", "Bayar", "Sainaa", "Software Engineer",
             2, 3.6);
  hashInsert(hashTable, "18B1DSS4010", "Tulga", "Tudev", "Electronic Engineer",
             4, 3.9);
  hashInsert(hashTable, "15B1DSS1042", "Tuguldur", "Davaa", "Computer Science",
             2, 3.1);
  hashInsert(hashTable, "15M1DSS1042", "Misheel", "Delger", "Software Engineer",
             3, 3.2);
  hashInsert(hashTable, "16B1DSS3121", "Zaya", "Erdene", "Electronic Engineer",
             1, 2.9);
  hashInsert(hashTable, "19D1DSS1375", "Ganaa", "Jargal", "Computer Science", 2,
             3.1);

  printHash(hashTable, hashSize);
  cout << "-----" << endl;

  string searchId = "14B1DSS6341";
  Student *result;
  result = search(hashTable, searchId);
  cout << "Search: " << searchId << endl;
  if (result != NULL)
    printStudent(result);
  else
    cout << -1 << endl;

  searchId = "15B1DSS1042";
  result = search(hashTable, searchId);
  cout << "Search: " << searchId << endl;
  if (result != NULL)
    printStudent(result);
  else
    cout << -1 << endl;

  searchId = "14B1DSS1375";
  result = search(hashTable, searchId);
  cout << "Search: " << searchId << endl;
  if (result != NULL)
    printStudent(result);
  else
    cout << -1 << endl;

  searchId = "19D1DSS1375";
  result = search(hashTable, searchId);
  cout << "Search: " << searchId << endl;
  if (result != NULL)
    printStudent(result);
  else
    cout << -1 << endl;

  hashInsert(hashTable, "24B1DSS4721", "Hello", "World", "Computer Science", 1,
             4.0);
  searchId = "24B1DSS4721";
  result = search(hashTable, searchId);
  cout << "Search: " << searchId << endl;
  if (result != NULL)
    printStudent(result);
  else
    cout << -1 << endl;

  hashRemove(hashTable, "17B1DSS1375");
  hashRemove(hashTable, "16B1DSS0053");
  hashRemove(hashTable, "13B1DSS3121");
  hashRemove(hashTable, "18B1DSS4010");
  cout << "-----" << endl;
  printHash(hashTable, hashSize);

  makeEmptyHashArray(hashTable, hashSize, 1);
  delete[] hashTable;
  return 0;
}

void makeEmptyHashArray(Student **ha, int size, int f) {
  for (int i = 0; i < size; i++) {
    if (f != 0) {
      makeEmpty(ha[i]);
    }
    ha[i] = NULL;
    delete ha[i];
  }
}
