#include"HashSep.h"
#define MinTableSize sizeof(struct ListNode)

struct ListNode {
	ElementType Element;
	Position Next;
};

typedef Position List;
/*List *TheList will be an array of lists,allocated later */
/*The lists use headers(for simplicity), */
/*though this wastes space */
struct HashTbl {
	int TableSize;
	List *TheLists;
};

/*HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;

	if (TableSize < MinTableSize) {
		/*ERROR OUTPUT*/
/*		printf("Table size too small");
		return NULL;
	}

	/*Allocate table */
/*	H = (HashTbl*)malloc(sizeof(struct HashTbl));
	if (NULL == H) {
		/*ERROR OUTPUT*/
//		printf("Out of space!!!");
/*	}


}*/