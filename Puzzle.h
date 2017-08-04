#pragma once
#include"List.h"
#include"Tree.h"

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

void ListDeleteCommon(List L);

void CheckBalanceSign(char signs[],int N);
void BackCal(char* expression[], int length);

int CalTreeNode(SearchTree T);
int CalTreeLeave(SearchTree T);
int CalTreeFullNode(SearchTree T);
void PrintTree(SearchTree T);
void PrintMidTree(SearchTree T,int K1,int K2);
int IsLikeTree(SearchTree T1, SearchTree T2);