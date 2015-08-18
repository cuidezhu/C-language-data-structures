#include <stdio.h>
#include <stdlib.h>
#define MaxData 10000

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
	int *Elements;
	int Size;
	int Capacity;
};

MaxHeap Creat(int MaxSize) {
	MaxHeap H = malloc(sizeof(struct HeapStruct));
	H->Elements = malloc((MaxSize+1) *sizeof(int));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	
	return H; 
}

void Insert(MaxHeap H, int item) {
	int i;
	if (IsFull(H)) {
		printf("Max heap is full");
		return;
	}
	i = ++H->Size;
	for ( ; H->Elements[i/2] < item; i/=2) {
		H->Elements[i] = H->Elements[i/2];
	}
	H->Elements[i] = item;
}

int DeleteMax(MaxHeap H) {
	int Parent, Child;
	int MaxItem, temp;
	if (IsEmpty(H)) {
		printf("The max heap is empty");
		return;
	}
	MaxItem = H->Elements[1];
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent*2<=H->Size; Parent=Child) {
		Child = Parent * 2;
		if ((Child!=H->Size) && (H->Elements[Child] < H->Elements[Child+1])) {
			Child++;
		}
		if (temp >= H->Elements[Child]) {
			break;
		}
		else {
			H->Elements[Parent] = H->Elements[Child];
		}
	}
	H->Elements[Parent] = temp;
	
	return MaxItem;
}

int IsFull(MaxHeap H) {
	if (H->Size == H->Capacity) {
		return 1;
	} 
}

int IsEmpty(MaxHeap H) {
	if (H->Size == 0) {
		return 0;
	}
}
int main() {
	
	return 0;
}
