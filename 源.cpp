#include"List.h"
#include"Puzzle.h"
#include"Tree.h"

#define N 10

int main() {
	int arr[6] = { 4,1,3,5,2,7 };
	BucketSort(arr, 6, 7);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}