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


int CalTreeNode(SearchTree root) {
	if (NULL == root) {
		return 0;
	}
	int NodeNum = 1;
	NodeNum += CalTreeNode(root->Left);
	NodeNum += CalTreeNode(root->Right);
	return NodeNum;
}
int CalTreeLeave(TreePosition T);
int CalTreeFullNode(TreePosition T);