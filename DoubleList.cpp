#include"DoubList.h"
#include"Universal.h"

struct DNode {
	ElementType Element;
	DPosition Pre;
	DPosition Next;
};

ElementType Retrieve(DPosition P) {
	return P->Element;
}

DPosition First(DoubleList L) {
	return L->Next;
}
DPosition Header(DoubleList L) {
	return L;
}
DPosition Advance(DPosition P) {
	return P->Next;
}
DPosition FindPrevious(DPosition P) {
	return P->Pre;
}
int IsEmpty(DoubleList L) {
	return L == NULL;
}
int IsLast(DPosition P,DoubleList L) {
	return P->Next == NULL;
}

DoubleList MakeEmpty(DoubleList DL) {
	DoubleList L = (DNode*)malloc(sizeof(DNode));
	L->Next = NULL;
	L->Pre = NULL;
	L->Element = 0;
	return L;
}
DPosition Find(ElementType X, DoubleList L) {
	DPosition tmp = L->Next;
	while (tmp != NULL) {
		if (tmp->Element == X) {
			break;
		}
		tmp = tmp->Next;
	}
	return tmp;
}
void DeleteList(DoubleList L) {
	DPosition P = L->Next;
	while (L != NULL) {
		P = P->Next;
		free(P->Pre);
	}
	free(L);
}
void Delete(ElementType X, DoubleList L) {
	DPosition P = L->Next;
	while (P != NULL) {
		if (P->Element == X) {
			DPosition tmp = P->Pre;
			tmp->Next = P->Next;
			P->Next->Pre = tmp;
			free(P);
			return;
		}
		P = P->Next;
	}
}
void Insert(ElementType X, DoubleList L, DPosition P) {
	DPosition inst = (DNode*)malloc(sizeof(DNode));
	inst->Element = X;
	if (IsLast(P,L)) {
		P->Next = inst;
		inst->Pre = P;
	}
	else {
		DPosition tmp = P->Next;
		P->Next = inst;
		inst->Pre = P;
		tmp->Pre = inst;
		inst->Next = tmp;
	}
}