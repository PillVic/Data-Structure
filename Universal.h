#pragma once

#include<math.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define IsEven(X) !(X&0x1==1)
#define MAX2(A,B) A>B?A:B

void swap(int *a, int *b);

int RandInt(int i, int j);
int GetNumber(int Number, int n);//�õ�������������nλ������

int NextPrime(int X);

//Ͱʽ����ͨ�������ռ�����ȡO(N)��ʱ�临�Ӷ�
//����ͨ���Ƚϣ����Ա�һ��ıȽ��������Ҫ��
void BucketSort(int arr[], int length, int range);
//�������򣬻���Ͱʽ����
//ͨ�����Ӷ���Ŀռ俪��(��������)����ȡ�ϸߵ�ִ���ٶ�
void RadixSort(int arr[], int length,int range);

struct Item {
	int Coefficient;
	int Exponent;
};
