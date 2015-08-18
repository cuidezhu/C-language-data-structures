#include <stdio.h>
#include <stdlib.h>

//have some bug

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode {
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

AVLTree SingleLeftRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
int GetHeight(BinTree BT);


AVLTree AVL_Insertion(int X, AVLTree T) {
	if (!T) {
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data) {
		T->Left = AVL_Insertion(X, T->Left);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (X < T->Left->Data) {
				T = SingleLeftRotation(T);
			}
			else {
				T = DoubleLeftRightRotation(T);
			}
		}
	}
	else if (X > T->Data) {
		T->Right = AVL_Insertion(X, T->Right);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (X > T->Right->Data) {
				T = SingleRightRotation(T);
			}
			else {
				T = DoubleRightLeftRotation(T); 
			} 
		} 
	}
	
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
}

AVLTree SingleLeftRotation(AVLTree A) {
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	
	return B;
}


AVLTree DoubleLeftRightRotation(AVLTree A) {
	A->Left = SingleRightRotation(A->Left);
	
	return SingleLeftRotation(A);
}

int GetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = (HL > HR) ? HL : HR;
		return (MaxH + 1);
	}
	else {
		return 0;
	}
}

int main() {
	
	
	return 0;
} 
