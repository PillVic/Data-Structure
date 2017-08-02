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
	/*Base Case*/
	if (NULL == root) {
		return 0;
	}
	int NodeNum = 1;
	NodeNum += CalTreeNode(root->Left);
	NodeNum += CalTreeNode(root->Right);
	return NodeNum;
}
int CalTreeLeave(SearchTree T) {
	/*Base Case*/
	if (NULL == T) {
		return 0;
	}
	else if (NULL==T->Left&&NULL==T->Right) {
		return 1;
	}

	int LeaveNum = 0;
	LeaveNum += CalTreeLeave(T->Left);
	LeaveNum += CalTreeLeave(T->Right);

	return LeaveNum;
}
int CalTreeFullNode(SearchTree T) {
	/*Base Case*/
	if (NULL == T) {
		return 0;
	}
	else if (NULL == T->Left || NULL == T->Right) {
		return 0;
	}

	int FulNodNum = 1;
	FulNodNum += CalTreeFullNode(T->Left);
	FulNodNum += CalTreeFullNode(T->Right);

	return FulNodNum;
}
void PrintMidTree(SearchTree T,int K1,int K2) {
	/*Print all the element between K1 and K2*/
	/*K1,K2 included*/
	/*Base Case*/
	if (T != NULL) {
		PrintMidTree(T->Left, K1, K2);
		if (T->Element >= K1&&T->Element <= K2) {
			printf("%d ", T->Element);
		}
		PrintMidTree(T->Right, K1, K2);
	}
}


