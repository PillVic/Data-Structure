#include"UniverSal.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"List.h"

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//随机数生成器，生成一个i和j之间的一个整数
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

int GetNumber(int Number, int N) {
	for (int step = 0; step < N-1; step++) {
		Number = Number / 10;
	}
	return Number % 10;
}

void BucketSort(int arr[], int N, int range) {
	//实现桶式排序
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
	free(table);
}
void RadixSort(int arr[], int N, int range){ 
	List result[10];
	int step = 0;
	int Time = ceil(log10(range));
	List resultLast[10];
	while (step < Time) {
		//Initial the array to store the list
		for (int i = 0; i < 10; i++) {
			result[i] = MakeEmpty(result[i]);
			resultLast[i] = result[i];
		}
		//Input the data into result array
		for (int indexArr = 0; indexArr < N; indexArr++) {
			int indexRes = GetNumber(arr[indexArr], step + 1);
			Insert(arr[indexArr], result[indexRes], resultLast[indexRes]);
			resultLast[indexRes] = resultLast[indexRes]->Next;
		}
		//Out put the data into arr
		int indexArr = 0;
		while (indexArr < N) {
			for (int indexRes = 0; indexRes < 10; indexRes++) {
				Position P = result[indexRes]->Next;
				while (P != NULL) {
					arr[indexArr] = P->Element;
					indexArr++;
					P = P->Next;
				}
			}
		}
		//free memory
		for (int index = 0; index < 10; index++) {
			DeleteList(result[index]);
		}
		step++;
	}
}




