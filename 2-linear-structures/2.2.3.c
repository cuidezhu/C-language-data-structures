#include <stdio.h>
#include <stdlib.h>

//堆栈的链式存储实现

typedef struct Node {
	int Data;
	struct Node *Next;
} LinkStack;
LinkStack *Top;

//堆栈初始化(建立空栈)
LinkStack *CreatStack() {			/*构建一个堆栈的头结点，返回指针*/
	LinkStack *S;
	S = (LinkStack *)malloc(sizeof(struct Node));
	S->Next = NULL;
	return S;
}

//判断堆栈S是否为空
int IsEmpty(LinkStack *S) {			/*判断堆栈S是否为空，若为空函数返回1，否则返回0 */
	return (S->Next == NULL);
}


//将元素item压入堆栈S, void Push(ElementType item, LinkStack *S)
void Push(int item, LinkStack *S) {
	struct Node *TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

//删除并返回堆栈S的栈顶元素 ElementType Pop(LinkStack *S)
int Pop(LinkStack *S) {
	struct Node *FirstCell;
	int TopElem;
	if (IsEmpty(S)) {
		printf("堆栈空");
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
