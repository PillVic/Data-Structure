#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>

#define N 20

using namespace std;

int main() {
	int arr[N] = { 0 };
	RandomSwap4(N,arr);
	for (int index = 0; index < N; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;
	RadixSort(arr, N, 100);
	for (int index = 0; index < N; index++) {
		cout << arr[index] << " ";
	}
	return 0;
}