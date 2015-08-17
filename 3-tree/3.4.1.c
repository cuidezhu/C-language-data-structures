#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

Position Find(int X, BinTree BST) {
	if (!BST) {
		return NULL;
	}
	if (X > BST->Data) {
		return Find(X, BST->Right);
	}
	else if (X < BST->Data) {
		return Find(X, BST->Left);
	}
	else {
		return BST;
	}
}

Position IterFind(int X, BinTree BST) {
	while (BST) {
		if (X > BST->Data) {
			BST = BST->Right;
		}
		else if (X < BST->Data) {
			BST = BST->Left;
		}
		else {
			return BST;
		}
	}
	return NULL;
}


Position FindMin(BinTree BST) {
	if (!BST) {
		return NULL;
	}
	else if (!BST->Left) {
		return BST;
	}
	else {
		return FindMin(BST->Left);
	}
}

Position FindMax(BinTree BST) {
	if (BST) {
		while (BST->Right) {
			BST = BST->Right;
		}
	}
	return BST;
}

BinTree Insert(int X, BinTree BST) {
	if (!BST) {
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (X < BST->Data) {
		BST->Left = Insert(X, BST->Left);
	}
	else if (X > BST->Data) {
		BST->Right = Insert(X, BST->Right);
	}
	
	return BST;
}

BinTree Delete(int X, BinTree BST) {
	Position Tmp;
	if (!BST) {
		printf("Don't found the element that should be delete.");
	}
	else if (X < BST->Data) {
		BST->Left = Delete(X, BST->Left);
	}
	else if (X > BST->Data) {
		BST->Right = Delete(X, BST->Right);
	}
	else if (BST->Left && BST->Right) {
		Tmp = FindMin(BST->Right);
		BST->Data = Tmp->Data;
		BST->Right = Delete(BST->Data, BST->Right);
	}
	else {
		Tmp = BST;
		if (!BST->Left) {
			BST = BST->Right;
		}
		else if (!BST->Right) {
			BST = BST->Left;
		}
		free(Tmp);
	}
	
	return BST;
}

int main() {
	
	return 0;
}
