//������к�����
#include <stdio.h>

int MaxSubseqSum1(int A[], int N);
int MaxSubseqSum2(int A[], int N);
int MaxSubseqSum3(int A[], int N);
int MaxSubseqSum4(int A[], int N);

int main() {
	int a[6] = {-2, 11, -4, 13, -5, -2};
	printf("MaxSubseqSum1(a, 6) = %d\n", MaxSubseqSum1(a, 6));
	printf("MaxSubseqSum2(a, 6) = %d\n", MaxSubseqSum2(a, 6));
	printf("MaxSubseqSum3(a, 6) = %d\n", MaxSubseqSum3(a, 6));
	printf("MaxSubseqSum4(a, 6) = %d\n", MaxSubseqSum4(a, 6));
	
	return 0;
}

//������������������� 
int MaxSubseqSum1(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0; i < N; i++) {			/*i�����к����λ�� */
		for (j = i; j < N; j++) {		/*j�����к��Ҷ�λ��*/ 
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum) {		/*����յõ���������к͸���*/ 
				MaxSum = ThisSum;		/*����½��*/ 
			}
		} 
	}
	
	return MaxSum; 
} 

//����һ��forѭ�� 
int MaxSubseqSum2(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for (i = 0; i < N; i++) {			/*i�����е����λ��*/ 
		ThisSum = 0;					/*ThisSum�Ǵ�A[i]��A[j]�����к�*/ 
		for (j = i; j < N; j++) {		/*j�������Ҷ�λ��*/ 
			ThisSum += A[j];			/*������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/ 
			if (ThisSum > MaxSum) {		/*����յõ���������к͸���*/ 
				MaxSum = ThisSum;		/*����½��*/ 
			}
		}
	}
	
	return MaxSum;
}

//�ֶ���֮,�㷨��ʱ�临�Ӷ�ΪO(NlogN)
int MaxSubseqSum3(int A[], int N) {	
	int i;
	int MaxLeft, MaxRight, MaxMiddle, MaxSum = 0;
	int Left[N/2], Right[N-N/2];		/*����������Ϊ������������,�������������� */
	
	if (N == 1) {						/*�ݹ��������*/
		MaxSum = A[0];
		return MaxSum;
	}
	 
	for (i = 0; i < N/2; i++) {
		Left[i] = A[i];					/*Ϊ������е����鸳ֵ*/
	} 
	
	for (i = N/2; i < N; i++) {
		Right[i-N/2] = A[i];			/*Ϊ�ұ����е����鸳ֵ*/
	}	
	
	//�õݹ鷽���ֱ����������е������������еĺ� 
	MaxLeft = MaxSubseqSum3(Left, N/2);
	MaxRight = MaxSubseqSum3(Right, N-N/2);
	
	//�������޵��������ֵMixMiddle
	int Max1 = A[N/2];
	int Max2 = A[N/2 - 1];
	int ThisSum = 0;
	for (i = N/2; i < N; i++) {			/*��ӽ������ҵ����ֵ*/
		ThisSum += A[i];
		if (ThisSum > Max1) {			
			Max1 = ThisSum;
		}
	}
	ThisSum = 0;
	for (i = N/2 - 1; i >= 0; i--) {	/*��ӽ�����������ֵ*/
		ThisSum += A[i];
		if (ThisSum > Max2) {
			Max2 = ThisSum;
		}
	}	
	MaxMiddle = Max1 + Max2;			/*����������ͼ�Ϊ������޵����е����ֵ*/
	
	//�����У������У�������޵��������ߵ����ֵ 
	MaxSum = MaxMiddle;
	if (MaxLeft>MaxMiddle && MaxLeft>MaxRight) {
		MaxSum = MaxLeft;
	}
	if (MaxRight>MaxMiddle && MaxRight>MaxLeft) {
		MaxSum = MaxRight;
	}
	
	return MaxSum;
} 

//���ߴ����㷨���㷨��ʱ�临�Ӷ�ΪO(N)
int MaxSubseqSum4(int A[], int N) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];				/*�����ۼ�*/ 
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;			/*���ָ��������µ�ǰ���*/ 
		}
		else if (ThisSum < 0) {			/*�����ǰ���к�Ϊ��*/ 
			ThisSum = 0;				/*�򲻿���ʹ����Ĳ��ֺ���������֮*/ 
		}
	}
	
	return MaxSum;
}
