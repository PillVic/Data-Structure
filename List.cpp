#include"List.h"
#include"Puzzle.h"
#include"Universal.h"


/*defined operator*/
static Position Max(Position P, Position L) {
	return Retrieve(P) > Retrieve(L) ? P : L;
}
static Position Min(Position P, Position L) {
	return Retrieve(P) < Retrieve(L) ? P : L;
}

/*给定指针，初始化链表*/
List MakeEmpty(List L) {
	L = (Node*)malloc(sizeof(Node));
	if (NULL == L) {
		printf("Out of space!!!");
		return NULL;
	}
	L->Element = 0;
	L->Next = NULL;
	return L;
}

int IsEmpty(List L) {
	return L->Next == NULL;
}

int IsLast(Position P) {
	return P->Next == NULL;
}

Position Find(ElementType X, List L) {
	PtrToNode tmpP = L->Next;
	while (tmpP->Next != NULL) {
		if (tmpP->Element == X) {
			return tmpP;
		}
		tmpP = tmpP->Next;
	}
	return NULL;
}

void Delete(ElementType X, List L) {
	Position P = FindPrevious(X, L);
	if (!IsLast(P)) {
		Position tmpCell = P->Next;
		P->Next = tmpCell->Next;
		free(tmpCell);
	}
}

Position FindPrevious(ElementType X, List L) {
	Position P = L;
	while (P->Next != NULL&&P->Next->Element != X) {
		P = P->Next;
	}
	return P;
}

/*插入指定元素到指定位置后面*/
void Insert(ElementType X, List L, Position P) {
	Position TmpCell = (Node*)malloc(sizeof(Node));
	if (TmpCell == NULL) {
		printf("Out of space!!!");
		return;
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L) {
	Position P = L->Next;
	L->Next = NULL;
	while (P != NULL) {
		Position Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

Position Header(List L) {
	return L;
}

Position First(List L) {
	return L->Next;
}

Position Advance(Position P) {
	return P->Next;
}

ElementType Retrieve(Position P) {
	if (P == NULL) {
		return NULL;
	}
	return P->Element;
}
