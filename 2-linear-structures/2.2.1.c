//栈的顺序存储实现 
#include <stdio.h>
#define MaxSize 5			/*储存数据元素的最大个数*/ 

typedef struct {
	int Data[MaxSize];
	int Top;
} Stack;


//入栈 void Push(Stack *PtrS, ElementType item);
void Push(Stack *PtrS, int item) {
	if (PtrS->Top == MaxSize-1) {
		printf("堆栈满");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

//出栈 ElementType Pop(Stack *PtrS)
int Pop(Stack *PtrS) {
	if (PtrS->Top == -1) {
		printf("堆栈空");
		return 0;			/*return ERROR; ERROR是ElementType的特殊值，标志错误*/			
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
} 




int main() {
	
	return 0;
} 
