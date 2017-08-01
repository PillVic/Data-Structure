#include"List.h"
#include"Puzzle.h"
#include"Tree.h"

#define N 10

int main() {
	/*Build a tree*/
	TreeNode Root;
	SearchTree T = &Root;
	Root.Left = Root.Right = NULL;
	Root.Element = 3;
	int arr[7] = { 1,4,6,9,2,5,7 };
	for (int i = 0; i < 7; i++) {
		TreeInsert(arr[i], T);
	}
	PrintTree(T);
	printf("\n%d", CalTreeFullNode(T));
	return 0;
}