#include"Puzzle.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define LINE  8

bool IsPrime(int n) {
	int i;
	for (i = 2; i < sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

void PrintPrimes(int N) {
	bool *arr = (bool *)malloc(N * sizeof(bool));
	for (int i = 0; i < N; i++) {
		arr[i] = true;
	}
	arr[0] = arr[1] = false;
	for (int i = 0; i < N; i++) {
		if (!arr[i]) {
			continue;
		}
		for (int j = 2; i*j <N; j++) {
			arr[i*j] = false;
		}
	}
	int element = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i]) {
			printf("%d ", i);
			element += 1;
		}
		if (element%LINE == 0) {
			printf("\n");
			element = 1;
		}
	}
	return;
}


int NextPrime(int X) {
	int t = X;
	if (IsEven(X)) {
		t += 1;
		if (IsPrime(X)) {
			return t;
		}
	}
	t += 2;
	while (!IsPrime(t)) {
		t += 2;
	}
	return t;
}