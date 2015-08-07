//线性表的链式存储实现(链表实现) 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
	int Data;									/*ElementType Data*/
	struct Node *Next;
} List;

List L, *PtrL;

//求表长(链表遍历方法)
int Length(List *PtrL) {
	List *p = PtrL;								/*p指向表的第一个结点*/ 
	int j = 0;
	while (p) {
		p = p->Next;
		j++;									/*当前p指向的是第j个结点*/ 
	}
	
	return j;
} 

//查找(按序号查找)
List *FindKth(int K, List *PtrL) {
	List *p = PtrL;
	int i = 1;
	while (p != NULL && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K) {
		return p;								/*找到第K个，返回指针*/ 
	}
	else {
		return NULL;							/*否则返回空*/ 
	}
} 

//查找(按值查找)
List *Find(int X, List *PtrL) {					/*List *Find(ElmentType X, List *PtrL)*/
	List *p = PtrL;
	while (p != NULL && p->Data != X) {
		p = p->Next;
	}
	return p;
} 

//插入(在第i-1(1<=i<=n+1)个结点后插入一个值为X的新结点)
List *Insert(int X, int i, List *PtrL) {
	List *p, *s;
	if (i == 1) {								/*新结点插入在表头*/ 
		s = (List*)malloc(sizeof(List));		/*申请、填装结点*/ 
		s->Data = X;
		s->Next = PtrL;
		return s;								/*返回新表头指针*/ 
	}
	p = FindKth(i-1, PtrL);						/*查找第i-1个结点*/ 
	if (p == NULL) {							/*第i-1个结点不存在，不能插入*/ 
		printf("参数i错");
		return NULL; 
	}
	else {
		s = (List*)malloc(sizeof(List));		/*申请、填装结点*/ 
		s->Data = X;
		s->Next = p->Next;						/*新结点插入在第i-1个结点的后面*/ 
		p->Next = s;
		return PtrL;
	}
	
}

//删除(删除链表中的第i(1<=i<=n)个位置上的结点)
List *Delete(int i, List *PtrL) {
	List *p, *s;
	
	if(i == 1) {								/*如果删除的是第1个结点*/ 
		s = PtrL;								/*s指向第1个结点*/ 
		if (PtrL != NULL) {						
			PtrL = PtrL->Next;					/*从链表中删除*/ 
		}
		else {
			return NULL;
		}
		free(s);								/*释放被删除结点*/ 
		
		return PtrL;
	}
	p = FindKth(i-1, PtrL);
	if (p == NULL) {							/*如果要删除的结点不存在*/	
		printf("第%d个元素不存在", i-1);
		return NULL;
	}
	s = p->Next;								/*s指向第i个结点*/ 
	if (s->Next == NULL) {						/*如果删除的是最后1个元素*/ 
		p = FindKth(i-1, PtrL);
		free(s);
		return NULL;
	}
	else {
		p->Next = s->Next;						/*从链表中删除*/ 
		free(s);								/*释放被删除结点*/ 		
		return PtrL;
	}
	

}

int main() {
	
	return 0;
}
