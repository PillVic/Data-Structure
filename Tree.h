#pragma once
#include"Universal.h"

#define ElementType int
struct TreeNode;
typedef struct TreeNode *TreePosition;
typedef struct TreeNode *SearchTree;

SearchTree TreeMakeEmpty(SearchTree T);
TreePosition TreeFind(ElementType X, SearchTree T);
TreePosition TreeFindMin(SearchTree T);
TreePosition TreeFindMax(SearchTree T);
SearchTree TreeInsert(ElementType X, SearchTree T);
SearchTree TreeDelete(ElementType X, SearchTree T);
ElementType Retrieve(TreePosition P);

struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
	int Height;
};