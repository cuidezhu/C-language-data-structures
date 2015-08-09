#include <stdio.h>
#define MaxSize 5			/*储存数据元素的最大个数*/ 


/*
 *用一个数组实现两个堆栈，要求最大的利用数组空间，使数组只要有空间，入栈操作就可以成功 
 *方法是使这两个栈分别从数组的两头开始向中间生长；当两个栈的栈顶指针相遇时，表示两个栈都满了 
 */
struct DStack {
	int Data[MaxSize];
	int Top1;			/*堆栈1的栈顶指针*/ 
	int Top2;			/*堆栈2的栈顶指针*/
} S;
/*
 *不知为何这两行会报错 
 *S.Top1 = -1;
 *S.Top2 = MaxSize;
 */
 
void Push(struct DStack *PtrS, int item, int Tag) {	/*Tag用于区分两个堆栈的标志，取值为1和2*/ 
	if (PtrS->Top2 - PtrS->Top1 == 1) {				/*堆栈满*/ 
		printf("堆栈满");
		return;
	} 
	if (Tag == 1) {			/*对第一个堆栈操作*/ 
		PtrS->Data[++(PtrS->Top1)] == item;
	}
	else {
		PtrS->Data[--(PtrS->Top2)] == item;
	}
}

int Pop(struct DStack *PtrS, int Tag) {
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {				/*第一个堆栈为空*/ 
			printf("堆栈空");
			return 0;						/*return ERROR; ERROR是ElementType的特殊值，标志错误*/
		}
		else {
			return PtrS->Data[(PtrS->Top1)--];
		} 
	}
	else {
		if (PtrS->Top2 == MaxSize) {		/*第二个堆栈为空*/ 
			printf("堆栈空");
			return 0;
		}
		else {
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
}

int main() {
	
	return 0;
}
