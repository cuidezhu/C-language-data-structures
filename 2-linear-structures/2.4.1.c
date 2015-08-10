//2.4 Application examples: polynomial additive operation
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
	int coef;
	int expon;
	struct PolyNode *link;
}  *Polynomial;

Polynomial P1, P2;

void Attach(int coef, int expon, Polynomial *PtrRear) {
	Polynomial P;
	
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expon = expon;
	
	(*PtrRear)->link = P;
	*PtrRear = P;
}

int Compare(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2) {
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (P1 && P2) {
		switch (Compare(P1->expon, P2->expon)) {
			case 1:
				Attach(P1->coef, P1->expon, &rear);
				P1 = P1->link;
				break;
			case -1:
				Attach(P2->coef, P2->expon, &rear);
				P2 = P2->link;
				break;
			case 0:
				sum = P1->coef + P2->coef;
				if (sum) {
					Attach(sum, P1->expon, &rear);
					P1 = P1->link;
					P2 = P2->link;
					break;
				} 
		}
	}
	for (; P1; P1=P1->link) {
		Attach(P1->coef, P1->expon, &rear);
	}
	for (; P2; P2=P2->link) {
		Attach(P2->coef, P2->expon, &rear);
	}
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}


int main() {
	
	
	return 0;
}
