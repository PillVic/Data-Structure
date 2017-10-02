#include"UniverSal.h"
#include"Puzzle.h"
#include<stdlib.h>
#include<stdio.h>


void RandomSwap1(int N, int arr[]) {
	for (int i = 0; i < N; i++) {
		int used;
		int element = RandInt(1, N);
		for (used = 0; used <= i; used++) {
			if (arr[used] == element) {
				element = RandInt(1, N);
				used = 0;
				continue;
			}
		}
		arr[i] = element;
		printf("%d ", arr[i]);
	}
}

void RandomSwap2(int N, int arr[]) {
	int *Used = (int*)calloc(N, sizeof(int));
	int element = RandInt(1, N);
	for (int i = 0; i < N; i++, element = RandInt(1, N)) {
		if (Used[element] == 1) {
			i--;
			continue;
		}
		arr[i] = element;
		Used[element] = 1;
		printf("%d ", arr[i]);
	}
}

void RandomSwap3(int N, int arr[]) {
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		swap(&arr[i], &arr[RandInt(0, i)]);
	}
}

//算法2的优化，通过顺序填入元素，回避Used数组的使用
void RandomSwap4(int N, int arr[]) {
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	int index = RandInt(0, N - 1);
	for (int element = 1; element <= N; element++) {
		if (arr[index] != 0) {
			index = RandInt(0, N - 1);
			element--;
			continue;
		}
		arr[index] = element;
	}
}