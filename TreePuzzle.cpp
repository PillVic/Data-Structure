#include"Tree.h"
#include"Puzzle.h"
#include"Universal.h"

void PrintTree(SearchTree T) {
	if (NULL != T) {
		PrintTree(T->Left);
		printf("%d ", T->Element);
		PrintTree(T->Right);
	}
}

int CalTreeNode(SearchTree root);
int CalTreeLeave(TreePosition T);
int CalTreeFullNode(TreePosition T);