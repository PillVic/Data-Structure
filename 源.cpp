#include"List.h"
#include"Puzzle.h"
#include"Tree.h"

#define N 10

int main() {
	/*Build a tree*/
	TreeNode Root1;
	TreeNode Root2;
	SearchTree T1 = &Root1;
	SearchTree T2 = &Root2;
	Root1.Left = Root1.Right = NULL;
	Root1.Element = 3;
	Root2.Left = Root2.Right = NULL;
	Root2.Element = 4;
	int arr[7] = { 1,4,6,9,2,5,7 };
	for (int i = 0; i < 7; i++) {
		TreeInsert(arr[i], T1);
		TreeInsert(arr[i] + 1, T2);
	}
	PrintTree(T1);
	printf("\n%d\n", CalTreeFullNode(T1));
	printf("%d", IsLikeTree(T1, T2));
	return 0;
}