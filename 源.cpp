#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>

#define N 20

using namespace std;


int main() {
	int arr[8] = { 3,3,4,2,4,4,2,4 };
	BucketSort(arr, 8, 10);
	PrintArr(arr, 8);
	cout << GetMainElement(arr, 8);
	return 0;
}
