#pragma once

#define ElementType int

struct DNode;

typedef struct DNode *PtrToDNode;
typedef PtrToDNode DoubleList;
typedef DoubleList DPosition;

DoubleList MakeEmpty(DoubleList L);
int IsEmpty(DoubleList L);
int IsLast(DPosition P, DoubleList L);
DPosition Find(ElementType X, DoubleList L);
void Delete(ElementType X, DoubleList L);
DPosition FindPrevious(DPosition P);
void Insert(ElementType X, DoubleList L, DPosition P);
void DeleteList(DoubleList L);
DPosition Header(DoubleList L);
DPosition Advance(DPosition P);
ElementType Retrieve(DPosition P);



