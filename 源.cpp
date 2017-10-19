#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>
#include"Stack.h"
#include"DoubList.h"

#define N 20

using namespace std;


int main() {
	DoubleList P = NULL;
	DoubleList L = MakeEmpty(P);
	for (int i = 0; i < 10; i++) {
		Insert(i+1, L, L);
	}
	Delete(3,L);
	P = L;
	while (!IsLast(P, L)) {
		printf("%d ", Retrieve(P));
		P = Advance(P);
	}
	cout << endl;
	P = FindPrevious(P);
	cout << Retrieve(P) << endl;
	return 0;
}
