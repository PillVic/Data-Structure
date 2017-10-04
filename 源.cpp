#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>

#define N 20

using namespace std;


int main() {
	int arr[N];
	RandomSwap4(N/2,arr);
	RandomSwap4(N / 2, arr + N / 2);
	PrintArr(arr, N);
	BucketSort(arr, N, N);
	PrintArr(arr, N);
	return 0;
}
