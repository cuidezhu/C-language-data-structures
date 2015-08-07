//���Ա��˳��洢ʵ��(����ʵ��)
#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 5

typedef struct {
	int Data[MAXSIZE];						/*ElementType Data[MAXSIZE]*/
	int Last;								/*Last�������Ա������һ��Ԫ�ص��±�*/ 
} List;

List L, *PtrL;								/*�����±�Ϊi��Ԫ�أ�L.Data[i]��PtrL->Data[i]*/

//��ʼ��(�����յ�˳���)
List *MakeEmpty() {
	List *PtrL;
	PtrL = (List *)malloc(sizeof(List));
	PtrL->Last = -1;						/*��ʱ���Ա���û��Ԫ�أ�����LastΪ-1*/ 
	
	return PtrL; 
} 

//����
int Find(int X, List *PtrL) {				/*int Find(ElmentType X, List *PtrL)*/
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X) {
		i++;
	}
	if (i > PtrL->Last) {
		return -1;							/*���û�ҵ�������-1*/ 
	}
	else {
		return i;							/*�ҵ��󷵻ص��Ǵ洢λ��*/ 
	}
} 

//����(��i(1<=i<=n+1)λ���ϲ���һ��ֵΪX����Ԫ��)
void Insert(int X, int i, List *PtrL) {		/*void Insert(ElementType X, int i, List *PtrL)*/
	int j;
	
	if (PtrL->Last == MAXSIZE) {			/*��ռ����������ܲ���*/ 
		printf("����");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2) {		/*������λ�õĺϷ���*/ 
		printf("λ�ò��Ϸ�");
		return;
	}
	for (j = PtrL->Last; j >= i-1; j++) {
		PtrL->Data[j+1] = PtrL->Data[j];	/*��a[i]~a[n]��������ƶ�*/ 
	}
	PtrL->Data[i-1] = X;					/*��Ԫ�ز���*/ 	
	PtrL->Last++;							/*Last��ָ�����Ԫ��*/ 
	
	return;
}

//ɾ��(ɾ�����еĵ�i(1<=i<=n)��λ���ϵ�Ԫ��) 
void Delete(int i, List *PtrL) {
	int j;
	if (i<1 || i>PtrL->Last+1) {			/*���ձ�ɾ��λ�õĺϷ���*/ 
		printf("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for (j = i-1; j < PtrL->Last; j++) {
		PtrL->Data[j] = PtrL->Data[j+1];	/*��a[i]~a[n]������ǰ�ƶ�*/
	}
	PtrL->Last--;
	
	return; 
}


int main() {
	
	
	return 0;
}
