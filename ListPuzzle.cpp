#include"List.h"
#include"Puzzle.h"
#include"UniverSal.h"

/*习题，打印链表元素*/
void PrintList(List Head) {
	Position P = First(Head);
	while (P != NULL) {
		printf("%d ", Retrieve(P));
		P = Advance(P);
	}
}
/*输出指定位置的元素*/
void PrintLots(List L, List P) {
	int Counter;
	Position Lpos, Ppos;
	Lpos = First(L);
	Ppos = First(P);
	Counter = 1;
	while (Lpos != NULL && Ppos != NULL) {
		if (Ppos->Element == Counter++) {     //Counter代表链表P中的元素位置
			printf("%d ", Lpos->Element);
			Ppos = Advance(Ppos);
		}
		Lpos = Advance(Lpos);
	}
}

void SwapNode(Position BeforeP, List L) {
	/*只有把函数体内内容放到主函数内才有作用*/
	Position P, AfterP;

	P = BeforeP->Next;
	AfterP = P->Next;

	P->Next = AfterP->Next;
	BeforeP->Next = AfterP;
	AfterP->Next = P;
}

void ListBoth(List L1, List L2) {
	Position L1Pos = First(L1);
	Position L2Pos = First(L2);
	List Result = NULL;
	Result = MakeEmpty(Result);
	Position RePos = Result;
	while (L1Pos != NULL && L2Pos != NULL) {
		if (L1Pos->Element < L2Pos->Element) {
			L1Pos = Advance(L1Pos);
		}
		else if (L1Pos->Element > L2Pos->Element) {
			L2Pos = Advance(L2Pos);
		}
		else {
			Insert(L1Pos->Element, Result, RePos);
			L1Pos = Advance(L1Pos);
			L2Pos = Advance(L2Pos);
			RePos = Advance(RePos);
		}
	}
	PrintList(Result);
}

void ListSum(List L1, List L2) {
	/*Build a list to store result*/
	List Result = MakeEmpty(NULL);
	Position RePos = Result;

	/*Let element in List L1 included first*/
	Position L1Pos = First(L1);
	while (L1Pos != NULL) {
		Insert(L1Pos->Element, L1, RePos);
		L1Pos = Advance(L1Pos);
		RePos = Advance(RePos);
	}

	/*Then include element only exist in List L2 */


	RePos = First(Result);
	Position L2Pos = First(L2);
	/*Add to  the head*/
	while (L2Pos != NULL&&L2Pos->Element<RePos->Element) {
		Insert(L2Pos->Element, Result, Result);
		L2Pos = Advance(L2Pos);
	}
	/*Find a Position to Insert*/
	while (L2Pos != NULL && !IsLast(RePos)) {
		if (L2Pos->Element > RePos->Element) {
			if (L2Pos->Element < Advance(RePos)->Element) {
				Insert(L2Pos->Element, Result, RePos);
				L2Pos = Advance(L2Pos);
			}
			else {
				RePos = Advance(RePos);
			}
		}
		else if (L2Pos->Element == RePos->Element) {
			L2Pos = Advance(L2Pos);
		}
	}                 /*Add  to List Result end*/
	while (L2Pos != NULL&&IsLast(RePos)) {
		Insert(L2Pos->Element, Result, RePos);
		L2Pos = Advance(L2Pos);
		RePos = Advance(RePos);
	}


	/*Output the result*/
	PrintList(Result);
}

void Josephus(int M, int N) {
	List Man = MakeEmpty(NULL);
	if (Man == NULL) {
		return;
	}
	/*Build the Man circle*/
	int Number = N + 1;
	while (--Number) {
		Insert(Number, Man, Man);
	}
	Position ManPos = First(Man);
	while (!IsLast(ManPos)) {
		ManPos = Advance(ManPos);
	}
	ManPos->Next = First(Man);
	/*Start the Game*/
	Number = N;
	int time = 0;
	ManPos = First(Man);
	M = M%N;
	while (Number != 1) {
		if (time == M) {
			if (ManPos == Advance(Man)) {
				Man->Next = Advance(ManPos);
			}
			printf("%d out\n", ManPos->Element);
			Position tmpPos = Advance(ManPos);
			Delete(Retrieve(ManPos), Advance(Man));
			ManPos = tmpPos;
			time = 0;
			Number--;
			continue;
		}
		time++;
		ManPos = Advance(ManPos);
	}
	printf("%d win\n", ManPos->Element);
	return;
}


void ListReverse1(List *L) {
	/*O(N^2)*/
	/*Use limited memory to reverse List L*/
	/*Plan A :swap the element data*/
	for (Position LPos1 = First(*L); !IsLast(LPos1); LPos1 = Advance(LPos1)) {
		for (Position LPos2 = Advance(LPos1); LPos2 != NULL; LPos2 = Advance(LPos2)) {
			swap(&LPos1->Element, &LPos2->Element);
		}
	}
}

void ListReverse2(List *L) {
	/*O(N)*/
	/*Need Extra memory O(N)*/
	List Result = MakeEmpty(NULL);
	Position LPos = First(*L);
	while (NULL != LPos) {
		Insert(LPos->Element, Result, Result);
		LPos = Advance(LPos);
	}
	DeleteList(*L);
	Position RPos = First(Result);
	LPos = *L;
	while (NULL != RPos) {
		Insert(RPos->Element, *L, LPos);
		RPos = Advance(RPos);
		LPos = Advance(LPos);
	}
}

void ListReverse3(List *L) {
	/*O(N)*/
	/*Use limited memory space*/
	Position LPos = First(*L);
	Position PreLPos = *L;
	Position NexLPos=NULL;
	Position LHeadPos = First(*L);
	while (!IsLast(LPos)) {
		NexLPos = LPos->Next;
		LPos->Next = PreLPos;
		PreLPos = LPos;
		LPos = NexLPos;
	}
	(*L)->Next = NexLPos;
	LPos->Next = PreLPos;
	LHeadPos->Next = NULL;
}