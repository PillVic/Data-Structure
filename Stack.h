#pragma once

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmptyStack(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmptyStack(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
