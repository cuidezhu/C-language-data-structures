//ջ��˳��洢ʵ�� 
#include <stdio.h>
#define MaxSize 5			/*��������Ԫ�ص�������*/ 

typedef struct {
	int Data[MaxSize];
	int Top;
} Stack;


//��ջ void Push(Stack *PtrS, ElementType item);
void Push(Stack *PtrS, int item) {
	if (PtrS->Top == MaxSize-1) {
		printf("��ջ��");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

//��ջ ElementType Pop(Stack *PtrS)
int Pop(Stack *PtrS) {
	if (PtrS->Top == -1) {
		printf("��ջ��");
		return 0;			/*return ERROR; ERROR��ElementType������ֵ����־����*/			
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
} 




int main() {
	
	return 0;
} 
