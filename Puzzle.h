#pragma once
#include"List.h"

int Choice1(int arr[], int k, int N);
int Choice2(int arr[], int k, int N);

void RandomSwap1(int N, int arr[]);
void RandomSwap2(int N, int arr[]);
void RandomSwap3(int N, int arr[]);
void RandomSwap4(int N, int arr[]);

int MinSubSum(const int arr[], int N);
int MinPositiveSubSum(const int arr[], int N);
int MaxSubProduct(const int arr[], int N);

bool IsPrime(int n);
void PrintPrimes(int N);

int GetMainElement1(int arr[], int N);


void PrintList(List Head);
void PrintLots(List L, List P);
void SwapNode(Position BeforeP, List L);

void ListBoth(List L1, List L2);
void ListSum(List L1, List L2);

void Josephus(int M, int N);

void ListReverse1(List *L);
void ListReverse2(List *L);
void ListReverse3(List *L);

void ListDeleteCommon(List *L);