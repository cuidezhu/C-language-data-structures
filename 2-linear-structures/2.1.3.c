#include <stdio.h>

//�����(Generalized List) 
typedef struct GNode {
	int Tag;							/*��־��0��ʾ����ǵ�Ԫ�أ�1��ʾ����ǹ����*/ 
	union {								/*�ӱ�ָ����Sublist�뵥Ԫ��������Data���ã������ô���ռ�*/ 
		int Data;						/*ElementType Data*/ 
		struct GNode *Sublist;
	} URegion;
	struct GNode *Next;					/*ָ���̽��*/ 
} GList;
					


int main() {
	
	return 0;
}
