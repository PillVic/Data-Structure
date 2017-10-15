#include"UniverSal.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"List.h"
#include"Puzzle.h"

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void PrintArr(int arr[], int length) {
	for (int index = 0; index < length; index++) {
		printf("%d ", arr[index]);
	}
	printf("\n");
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

void BucketSort(int A[], int N, int range) {
	//实现桶式排序
	int *Table = (int*)malloc(range * sizeof(int));
	for (int index = 0; index < range; index++) {
		Table[index] = 0;
	}
	//sort the data
	for (int indexA = 0; indexA < N; indexA++) {
		Table[A[indexA]] += 1;
	}
	//input the data into A array
	int indexA = 0;
	for (int indexTable = 0; indexTable < range; indexTable++) {
		while (Table[indexTable] != 0) {
			A[indexA] = indexTable;
			indexA++;
			Table[indexTable]--;
		}
	}
	free(Table);
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

int GetMainElement(int A[], int N) {
	printf("A:");
	PrintArr(A, N);
	if (N == 2) {
		if (A[0] == A[1]) {
			return A[0];
		}
		else {
			return -1;
		}
	}
	else if (N == 1) {
		return A[0];
	}
	if (!IsEven(N)) {
		int result = GetMainElement(A, N - 1);
		if (result != -1) {
			return result;
		}
		else {
			int time = 0;
			for (int index = 0; index < N; index++) {
				if (A[index] == A[N - 1]) {
					time += 1;
				}
			}
			if (time > N / 2) {
				return A[N - 1];
			}
			else {
				return -1;
			}
		}
	}
	int *B = (int*)malloc(N * sizeof(int));
	int indexB = 0;
	for (int indexA = 0; indexA+1 < N; indexA += 2) {
		if (A[indexA] == A[indexA+1]) {
			B[indexB] = A[indexA];
			indexB++;
		}
	}
	printf("B: ");
	PrintArr(B, indexB);
	int result=GetMainElement(B, indexB);
	free(B);
	return result;
}


int GetMainElement2(int A[], int length) {
	//copy the array
	int max = A[0];
	for (int indexA = 0; indexA < length; indexA++) {
		if (max < A[indexA]) {
			max = A[indexA];
		}
	}
	int *tmp = (int*)malloc(length * sizeof(int));
	for (int index = 0; index < length; index++) {
		tmp[index] = A[index];
	}
	BucketSort(tmp, length, max+10);
	//get the element which  has the only posibility to be
	int half = (int)ceil(length*1.0 / 2);
	for (int index = 0; index < half; index++) {
		int head = tmp[index];
		int tail = tmp[index + half-1];
		if (head == tail) {
			free(tmp);
			return head;
		}
	}
	free(tmp);
	printf("No main element!!!\n");
	return -1;
}
