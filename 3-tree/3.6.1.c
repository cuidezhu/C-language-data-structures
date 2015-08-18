#include <stdio.h>

typedef struct LinkTable *Ptr;
struct LinkTable {
	int Data;
	Ptr next;
};

Ptr reverse(Ptr head, int K) {
	int cnt;
	Ptr newNode, oldNode, tmp;
	cnt = 1;
	newNode = head->next;
	oldNode = newNode->next;
	while (cnt < K) {
		tmp = oldNode->next;
		oldNode->next = newNode;
		newNode = oldNode;
		oldNode = tmp;
		cnt++;
	}
	head->next->next = oldNode;
	
	return newNode;
}

int main() {
	
	
	return 0;
}
