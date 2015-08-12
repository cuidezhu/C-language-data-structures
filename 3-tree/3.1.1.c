#include <stdio.h>
#define MAXSIZE 10

typedef struct {
	int Data[MAXSIZE];
	int Length;
	
} StaticTable; 

//Sequential search
int SequentialSearch(StaticTable *Tb1, int K) {
	int i;
	Tb1->Data[0] = K;
	for (i = Tb1->Length; Tb1->Data[i] != K; i--);
	
	return i;
}

//Binary search
int BinarySearch(StaticTable *Tb, int K) {
	int left, right, mid, NotFound = -1;
	
	left = 1;
	right = Tb->Length;
	while (left <= right) {
		mid = (left + right) / 2;
		if (K < Tb->Data[mid]) {
			right = mid - 1;
		}
		else if (K > Tb->Data[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	
	return NotFound;
}

int main() {
	
	
	return 0;
}
