#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>
#include"Stack.h"

#define N 20

using namespace std;


int main() {
	char expressions[11] = { '6','5','2','3','+','8','*','+','3','+','*' };
	cout << PostfixExpressions(expressions, 11 - 1) << endl;
	return 0;
}
