#include"Tree.h"
#include"Universal.h"

static int Height(TreePosition P) {
	if (NULL == P) {
		return -1;
	}
	else {
		return P->Height;
	}
}
/*This function can be called only if K2 has a left child*/
/*Perform a rotate betwwen a node(K2) and its left child*/
/*Update heights,then return new root*/
static TreePosition SingleRotateWithLeft(TreePosition K2) {
	TreePosition K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = MAX2(Height(K2->Left),
		              Height(K2->Right)) + 1;
	K1->Height = MAX2(Height(K1->Left), K2->Height) + 1;

	return K1;   /*New root*/
}
/*Same as SingleRotateWithLeft,swap right,left*/
static TreePosition SingleRotateWithRight(TreePosition K2) {
	TreePosition K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = MAX2(Height(K2->Right),
		              Height(K2->Left)) + 1;
	K1->Height = MAX2(Height(K1->Right), K2->Height) + 1;

	return K1;
}

/*This function can be called only if K3 has a left */
/*child and K3's left child has a right child*/
/*Do the left-right double rotation*/
/*Update heights,then return new root*/
static TreePosition DoubleRotateWithLeft(TreePosition K3) {
	/*Rotate between K11and K2*/
	K3->Left = SingleRotateWithRight(K3->Left);

	/*Rotate beetween K3 and K2*/
	return SingleRotateWithLeft(K3);
}
/*Same as DoubleRotateWithLeft,Just swap right left*/
static TreePosition DoubleRotateWithRight(TreePosition K3) {

	/*Rotate between K1 and K2*/
	K3->Right = SingleRotateWithLeft(K3->Right);

	/*Rotate beetween K3 and K2*/
	return SingleRotateWithRight(K3);
}

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
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (NULL == T) {
			/*Error output*/
			printf("Out of space!!!");
		}
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = TreeInsert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) {
			if (X < T->Left->Element) {
				T = SingleRotateWithLeft(T);
			}
			else {
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (X > T->Element) {
		T->Right = TreeInsert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2) {
			if (X > T->Right->Element) {
				T = SingleRotateWithRight(T);
			}
			else {
				T = DoubleRotateWithRight(T);
			}
		}
	}
	/*Else X is in the tree already;we'll do nothing */

	T->Height = MAX2(Height(T->Left), Height(T->Right)) + 1;
	return T;
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
