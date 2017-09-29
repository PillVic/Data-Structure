#pragma once

#include<math.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define IsEven(X) !(X&0x1==1)
#define MAX2(A,B) A>B?A:B

void swap(int *a, int *b);

int RandInt(int i, int j);


int NextPrime(int X);

//桶式排序，通过牺牲空间来换取O(N)的时间复杂度
//不是通过比较，所以比一般的比较排序绝对要快
void BucketSort(int arr[], int length, int range);

struct Item {
	int Coefficient;
	int Exponent;
};
