#pragma once

#include<math.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define IsEven(X) !(X&0x1==1)
#define MAX2(A,B) A>B?A:B

void PrintArr(int arr[], int length);
void swap(int *a, int *b);

int RandInt(int i, int j);
int GetNumber(int Number, int n);//得到从右往左数第n位的数字

int NextPrime(int X);

//桶式排序，通过牺牲空间来换取O(N)的时间复杂度
//不是通过比较，所以比一般的比较排序绝对要快
void BucketSort(int arr[], int length, int range);
//基数排序，基于桶式排序
//通过增加额外的空间开销(保存链表)来换取较高的执行速度
void RadixSort(int arr[], int length,int range);

struct Item {
	int Coefficient;
	int Exponent;
};
