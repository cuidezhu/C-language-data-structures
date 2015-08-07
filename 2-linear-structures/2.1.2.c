//���Ա����ʽ�洢ʵ��(����ʵ��) 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
	int Data;									/*ElementType Data*/
	struct Node *Next;
} List;

List L, *PtrL;

//���(�����������)
int Length(List *PtrL) {
	List *p = PtrL;								/*pָ���ĵ�һ�����*/ 
	int j = 0;
	while (p) {
		p = p->Next;
		j++;									/*��ǰpָ����ǵ�j�����*/ 
	}
	
	return j;
} 

//����(����Ų���)
List *FindKth(int K, List *PtrL) {
	List *p = PtrL;
	int i = 1;
	while (p != NULL && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K) {
		return p;								/*�ҵ���K��������ָ��*/ 
	}
	else {
		return NULL;							/*���򷵻ؿ�*/ 
	}
} 

//����(��ֵ����)
List *Find(int X, List *PtrL) {					/*List *Find(ElmentType X, List *PtrL)*/
	List *p = PtrL;
	while (p != NULL && p->Data != X) {
		p = p->Next;
	}
	return p;
} 

//����(�ڵ�i-1(1<=i<=n+1)���������һ��ֵΪX���½��)
List *Insert(int X, int i, List *PtrL) {
	List *p, *s;
	if (i == 1) {								/*�½������ڱ�ͷ*/ 
		s = (List*)malloc(sizeof(List));		/*���롢��װ���*/ 
		s->Data = X;
		s->Next = PtrL;
		return s;								/*�����±�ͷָ��*/ 
	}
	p = FindKth(i-1, PtrL);						/*���ҵ�i-1�����*/ 
	if (p == NULL) {							/*��i-1����㲻���ڣ����ܲ���*/ 
		printf("����i��");
		return NULL; 
	}
	else {
		s = (List*)malloc(sizeof(List));		/*���롢��װ���*/ 
		s->Data = X;
		s->Next = p->Next;						/*�½������ڵ�i-1�����ĺ���*/ 
		p->Next = s;
		return PtrL;
	}
	
}

//ɾ��(ɾ�������еĵ�i(1<=i<=n)��λ���ϵĽ��)
List *Delete(int i, List *PtrL) {
	List *p, *s;
	
	if(i == 1) {								/*���ɾ�����ǵ�1�����*/ 
		s = PtrL;								/*sָ���1�����*/ 
		if (PtrL != NULL) {						
			PtrL = PtrL->Next;					/*��������ɾ��*/ 
		}
		else {
			return NULL;
		}
		free(s);								/*�ͷű�ɾ�����*/ 
		
		return PtrL;
	}
	p = FindKth(i-1, PtrL);
	if (p == NULL) {							/*���Ҫɾ���Ľ�㲻����*/	
		printf("��%d��Ԫ�ز�����", i-1);
		return NULL;
	}
	s = p->Next;								/*sָ���i�����*/ 
	if (s->Next == NULL) {						/*���ɾ���������1��Ԫ��*/ 
		p = FindKth(i-1, PtrL);
		free(s);
		return NULL;
	}
	else {
		p->Next = s->Next;						/*��������ɾ��*/ 
		free(s);								/*�ͷű�ɾ�����*/ 		
		return PtrL;
	}
	

}

int main() {
	
	return 0;
}
