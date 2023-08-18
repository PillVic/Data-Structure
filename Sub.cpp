#include"Puzzle.h"

//模仿最大序列和的算法4
int MinSubSum(int arr[], int N) {
	int MinSum = arr[0];
	int ThisSum = 0;
	for (int i = 0; i < N; i++) {
		ThisSum += arr[i];
		if (ThisSum < MinSum) {
			MinSum = ThisSum;
		}
		else if (ThisSum > 0) {
			ThisSum = arr[i];
		}
	}
	return MinSum;
}
