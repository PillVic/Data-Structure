#include"UniverSal.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>


void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//�����������������һ��i��j֮���һ������
int RandInt(int i, int j) {
	if (i == j) {
		return i;
	}
	int end = i > j ? i : j;
	int bgn = i + j - end;

	int r = rand();
	r = r % (end - bgn + 1) + bgn;
	return r;
}

void BucketSort(int arr[], int N, int range) {
	//ʵ��Ͱʽ����
	if (range <= 0) {
		printf("Wrong range!!!");
		return;
	}
	bool *table = (bool*)malloc(range * sizeof(bool));
	for (int i = 0; i < range; i++) {
		table[i] = false;
	}
	for (int i = 0; i < N; i++) {
		table[arr[i]] = true;
	}
	int Aindex = 0; int Tindex = 0;
	while (Aindex < N&&Tindex<range) {
		if (table[Tindex]) {
			arr[Aindex] = Tindex;
			Aindex++;
		}
		Tindex++;
	}
}
