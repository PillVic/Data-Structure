#include"Stack.h"
#include"UniverSal.h"

struct Node {
	ElementType Element;
	PtrToNode Next;
};

int IsEmptyStack(Stack S) {
	return NULL == S->Next;
}

Stack CreateStack(void) {
	Stack S;
	S = (Node*)malloc(sizeof(struct Node));
	if (NULL == S) {
		printf("Out of space!!!");
		return S;
	}
	S->Element = 0;
	S->Next = NULL;
	return S;
}

void MakeEmpty(Stack S) {
	if (NULL == S) {
		printf("Must use CreateStack first");
	}
	else {
		while (!IsEmptyStack(S)) {
			Pop(S);
		}
	}
}

void Push(ElementType X, Stack S) {
	PtrToNode TmpCell;

	TmpCell = (Node*)malloc(sizeof(struct Node));
	if (NULL == TmpCell) {
		printf("Out of space!!!");
	}
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S) {
	if (!IsEmptyStack(S)) {
		return S->Next->Element;
	}
	printf("Empty stack");
	return 0; /*Return value used to avoid warning*/
}

void Pop(Stack S) {
	PtrToNode FirstCell;

	if (IsEmptyStack(S)) {
		printf("Empty stack");
	}
	else {
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}