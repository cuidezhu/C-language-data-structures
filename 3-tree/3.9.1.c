#include <stdio.h>
#define MaxSize 100

typedef struct {
	int Data;
	int Parent;
} SetType;

int Find(SetType S[], int X) {
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
	if (i >= MaxSize) return -1;
	for ( ; S[i].Parent >= 0; i = S[i].Parent);
	return i;
}

void Union(SetType S[], int X1, int X2) {
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if (Root1 != Root2) S[Root2].Parent = Root1; 
}


int main() {
	
	return 0;
}
