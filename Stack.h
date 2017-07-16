#pragma once

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmptyStack(Stack S);
Stack CreateStack(Stack S);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
