#include <stdio.h>
#define MaxSize 5			/*��������Ԫ�ص�������*/ 


/*
 *��һ������ʵ��������ջ��Ҫ��������������ռ䣬ʹ����ֻҪ�пռ䣬��ջ�����Ϳ��Գɹ� 
 *������ʹ������ջ�ֱ���������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ������ 
 */
struct DStack {
	int Data[MaxSize];
	int Top1;			/*��ջ1��ջ��ָ��*/ 
	int Top2;			/*��ջ2��ջ��ָ��*/
} S;
/*
 *��֪Ϊ�������лᱨ�� 
 *S.Top1 = -1;
 *S.Top2 = MaxSize;
 */
 
void Push(struct DStack *PtrS, int item, int Tag) {	/*Tag��������������ջ�ı�־��ȡֵΪ1��2*/ 
	if (PtrS->Top2 - PtrS->Top1 == 1) {				/*��ջ��*/ 
		printf("��ջ��");
		return;
	} 
	if (Tag == 1) {			/*�Ե�һ����ջ����*/ 
		PtrS->Data[++(PtrS->Top1)] == item;
	}
	else {
		PtrS->Data[--(PtrS->Top2)] == item;
	}
}

int Pop(struct DStack *PtrS, int Tag) {
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {				/*��һ����ջΪ��*/ 
			printf("��ջ��");
			return 0;						/*return ERROR; ERROR��ElementType������ֵ����־����*/
		}
		else {
			return PtrS->Data[(PtrS->Top1)--];
		} 
	}
	else {
		if (PtrS->Top2 == MaxSize) {		/*�ڶ�����ջΪ��*/ 
			printf("��ջ��");
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
