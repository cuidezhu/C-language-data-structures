//Queue(chain table implement)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int Data;
	struct Node *Next;
} QNode;

typedef struct {
	QNode *rear;
	QNode *front;
} LinkQueue;

LinkQueue *PtrQ;

//Delete, int is an ElementType, it can be replace
int DeleteQ(LinkQueue *PtrQ) {
	QNode *FrontCell;
	int FrontElem;
	
	if (PtrQ->front == NULL) {
		printf("Queue is empty");
		return 0;
	}
	
	FrontCell = PtrQ->front;
	
	if (PtrQ->front == PtrQ->rear) {			/*if queue only have one element*/
		PtrQ->front = PtrQ->rear = NULL;		/*queue is empty after delete*/
	}
	else {
		PtrQ->front = PtrQ->front->Next;
	}
	
	FrontElem = FrontCell->Data;
	free(FrontCell);							/*free the space of the node that have been delete*/
	
	return FrontElem; 
}

int main() {
	
	return 0;
}
