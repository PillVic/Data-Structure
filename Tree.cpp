#include"Tree.h"


SearchTree TreeMakeEmpty(SearchTree T) {
	if (T != NULL) {
		TreeMakeEmpty(T->Left);
		TreeMakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

TreePosition TreeFind(ElementType X, SearchTree T) {
	if (NULL == T) {
		return NULL;
	}else if (X < T->Element) {
		return TreeFind(X, T->Left);
	}
	else if (X > T->Element) {
		return TreeFind(X, T->Right);
	}
	else {
		return T;
	}
}

TreePosition TreeFindMin(SearchTree T) {
	if (NULL != T) {
		while (T->Left != NULL) {
			T = T->Left;
		}
	}
	return T;
}

TreePosition TreeFindMax(SearchTree T) {
	if (NULL != T) {
		while (T->Right != NULL) {
			T = T->Right;
		}
	}
	return T;
}

SearchTree TreeInsert(ElementType X, SearchTree T) {
	if (NULL == T) {
		/*Create and return a one-node tree*/
		T = (TreeNode*)malloc(sizeof(struct TreeNode));
		if (NULL == T) {
			printf("Out of space!!!");
		}
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = TreeInsert(X, T->Left);
	}
	else if (X > T->Element) {
		T->Right = TreeInsert(X, T->Right);
	}
	/*Else X is in the tree already;we'll do nothing*/
	return T;  /*Do not forget this line!!!*/
}

SearchTree TreeDelete(ElementType X, SearchTree T) {
	TreePosition TmpCell;
	if (NULL == T) {
		printf("Element not found");
	}
	else if (X < T->Element) { /*Go left*/
		T->Left = TreeDelete(X, T->Left);
	}
	else if (X > T->Element) { /*Go right*/
		T->Right = TreeDelete(X, T->Right);
	}
	else if (T->Left&&T->Right) { /*Two children*/
		/*Replace with smallest in right subtree*/
		TmpCell = TreeFindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = TreeDelete(T->Element, T->Right);
	}
	else {   /*One or zero children*/
		TmpCell = T;
		if (NULL == T->Left) { /*Also handles 0 children*/
			T = T->Right;
		}
		else if (NULL == T->Right) {
			T = T->Left;
		}
		free(TmpCell);
	}
	return T;
}

ElementType Retrieve(TreePosition P) {
	return P->Element;
}
