#include <stdio.h>
#include <stdlib.h>

//��ջ����ʽ�洢ʵ��

typedef struct Node {
	int Data;
	struct Node *Next;
} LinkStack;
LinkStack *Top;

//��ջ��ʼ��(������ջ)
LinkStack *CreatStack() {			/*����һ����ջ��ͷ��㣬����ָ��*/
	LinkStack *S;
	S = (LinkStack *)malloc(sizeof(struct Node));
	S->Next = NULL;
	return S;
}

//�ж϶�ջS�Ƿ�Ϊ��
int IsEmpty(LinkStack *S) {			/*�ж϶�ջS�Ƿ�Ϊ�գ���Ϊ�պ�������1�����򷵻�0 */
	return (S->Next == NULL);
}


//��Ԫ��itemѹ���ջS, void Push(ElementType item, LinkStack *S)
void Push(int item, LinkStack *S) {
	struct Node *TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

//ɾ�������ض�ջS��ջ��Ԫ�� ElementType Pop(LinkStack *S)
int Pop(LinkStack *S) {
	struct Node *FirstCell;
	int TopElem;
	if (IsEmpty(S)) {
		printf("��ջ��");
		return 0;
	} else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
	}
}

int main() {


	return 0;
}
