#pragma once
#include"Universal.h"
#define ElementType int

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DetroyTable(HashTable H);
Position HashFind(ElementType Key, HashTable H);
void HashInsert(ElementType Key, HashTable H);
ElementType HashRetrieve(Position P);
