#include <stdio.h>

//广义表(Generalized List) 
typedef struct GNode {
	int Tag;							/*标志域：0表示结点是单元素，1表示结点是广义表*/ 
	union {								/*子表指针域Sublist与单元素作用域Data复用，即共用储存空间*/ 
		int Data;						/*ElementType Data*/ 
		struct GNode *Sublist;
	} URegion;
	struct GNode *Next;					/*指向后继结点*/ 
} GList;
					


int main() {
	
	return 0;
}
