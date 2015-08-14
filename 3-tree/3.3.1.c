#include <stdio.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

void PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}


void InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
} 

void PreOrderPrintLeaves(BinTree BT) {
	if (BT) {
		if (!BT->Left &&!BT->Right) {
			printf("%d", BT->Data);
		}
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
} 

int PostOrderGetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);
		HR = PostOrderGetHeight(BT->Right);
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
