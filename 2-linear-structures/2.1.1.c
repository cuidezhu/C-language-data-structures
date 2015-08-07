//线性表的顺序存储实现(数组实现)
#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 5

typedef struct {
	int Data[MAXSIZE];						/*ElementType Data[MAXSIZE]*/
	int Last;								/*Last代表线性表中最后一个元素的下标*/ 
} List;

List L, *PtrL;								/*访问下标为i的元素：L.Data[i]或PtrL->Data[i]*/

//初始化(建立空的顺序表)
List *MakeEmpty() {
	List *PtrL;
	PtrL = (List *)malloc(sizeof(List));
	PtrL->Last = -1;						/*此时线性表中没有元素，所以Last为-1*/ 
	
	return PtrL; 
} 

//查找
int Find(int X, List *PtrL) {				/*int Find(ElmentType X, List *PtrL)*/
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X) {
		i++;
	}
	if (i > PtrL->Last) {
		return -1;							/*如果没找到，返回-1*/ 
	}
	else {
		return i;							/*找到后返回的是存储位置*/ 
	}
} 

//插入(第i(1<=i<=n+1)位置上插入一个值为X的新元素)
void Insert(int X, int i, List *PtrL) {		/*void Insert(ElementType X, int i, List *PtrL)*/
	int j;
	
	if (PtrL->Last == MAXSIZE) {			/*表空间已满，不能插入*/ 
		printf("表满");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2) {		/*检查插入位置的合法性*/ 
		printf("位置不合法");
		return;
	}
	for (j = PtrL->Last; j >= i-1; j++) {
		PtrL->Data[j+1] = PtrL->Data[j];	/*将a[i]~a[n]倒序向后移动*/ 
	}
	PtrL->Data[i-1] = X;					/*新元素插入*/ 	
	PtrL->Last++;							/*Last仍指向最后元素*/ 
	
	return;
}

//删除(删除表中的第i(1<=i<=n)个位置上的元素) 
void Delete(int i, List *PtrL) {
	int j;
	if (i<1 || i>PtrL->Last+1) {			/*检查空表即删除位置的合法性*/ 
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i-1; j < PtrL->Last; j++) {
		PtrL->Data[j] = PtrL->Data[j+1];	/*将a[i]~a[n]倒序向前移动*/
	}
	PtrL->Last--;
	
	return; 
}


int main() {
	
	
	return 0;
}
