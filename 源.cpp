#include"List.h"
#include"Puzzle.h"
#include"Tree.h"
#include"Universal.h"
#include<iostream>
#include"Stack.h"

#define N 20

using namespace std;


int main() {
	char sign[6] = "'(])'";
	if (CheckBalanceSign(sign, 6)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
