#include"List.h"
#include"Puzzle.h"

#define N 10

int main() {
	List L = MakeEmpty(NULL);
	for (int i = 0; i < N; i++) {
		Insert(N - i, L, L);
	}
	Insert(5, L, L);
	Insert(3, L, L);
	PrintList(L);
	printf("\n");
	ListDeleteCommon(L);
	PrintList(L);
	return 0;
}