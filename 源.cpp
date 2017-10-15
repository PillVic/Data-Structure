#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>

#define N 20

using namespace std;


int main() {
	int arr[9] = { 3,3,4,2,4,4,2,4,4 };
	cout << GetMainElement(arr, 9);
	return 0;
}
