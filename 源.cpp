#include"List.h"
#include"Puzzle.h"

#define N 7

int main() {
	List L = MakeEmpty(NULL);
	for (int i = 0; i < N; i++) {
		Insert(N - i, L, L);
	}
	PrintList(L);
	ListReverse3(&L);
	printf("\n");
	PrintList(L);
	return 0;
}