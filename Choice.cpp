#include"Puzzle.h"
#include"Universal.h"

//冒泡法排序后返回
int Choice1(int arr[], int k, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[i] < arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
	return arr[k];
}

//选择排序部分后返回(找寻k次剩余元素中的最大值)
int Choice2(int arr[], int k, int N) {
	for (int i = 0; i <= k; i++) {
		for (int j = i; j < N; j++) {
			if (arr[j] > arr[i]) {
				swap(&arr[j], &arr[i]);
			}
		}
	}
	return arr[k];
}
