#include"Puzzle.h"
#include"UniverSal.h"

//ð�ݷ�����󷵻�
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

//ѡ�����򲿷ֺ󷵻�(��Ѱk��ʣ��Ԫ���е����ֵ)
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