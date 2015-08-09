//Queue(array implement)
#include <stdio.h>
#define MaxSize 5

typedef struct {
	int Data[MaxSize];
	int rear;
	int front;
} Queue;


//Add, int is an ElementType
void Add(Queue *PtrQ, int item) {
	if ((PtrQ->rear+1) % MaxSize == PtrQ->front) {
		printf("Queue is full");
		return;
	}
	PtrQ->rear = (PtrQ->rear+1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}

//Delete, int is an ElementType
int DeleteQ(Queue *PtrQ) {
	if (PtrQ->front == PtrQ->rear) {
		printf("Queue is Empty");
		return 0;
	}
	else {
		PtrQ->front = (PtrQ->front+1)%MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
}


int main() {	
	
	return 0;
}

