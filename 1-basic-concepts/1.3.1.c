//最大子列和问题
#include <stdio.h>

int MaxSubseqSum1(int A[], int N);
int MaxSubseqSum2(int A[], int N);

int main() {
	int a[4] = {1, 3, -2, 5};
	
	printf("MaxSubseqSum1(a, 4) = %d\n", MaxSubseqSum1(a, 4));
	printf("MaxSubseqSum2(a, 4) = %d\n", MaxSubseqSum2(a, 4));
	printf("MaxSubseqSum3(a, 4) = %d\n", MaxSubseqSum3(a, 4));
	
	return 0;
}

//暴力解决，穷举所有情况 
int MaxSubseqSum1(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0; i < N; i++) {			/*i是子列和左端位置 */
		for (j = i; j < N; j++) {		/*j是子列和右端位置*/ 
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum) {		/*如果刚得到的这个子列和更大*/ 
				MaxSum = ThisSum;		/*则更新结果*/ 
			}
		} 
	}
	
	return MaxSum; 
} 

//减少一个for循环 
int MaxSubseqSum2(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for (i = 0; i < N; i++) {			/*i是子列的左端位置*/ 
		ThisSum = 0;					/*ThisSum是从A[i]到A[j]的子列和*/ 
		for (j = i; j < N; j++) {		/*j是子列右端位置*/ 
			ThisSum += A[j];			/*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/ 
			if (ThisSum > MaxSum) {		/*如果刚得到的这个子列和更大*/ 
				MaxSum = ThisSum;		/*则更新结果*/ 
			}
		}
	}
	
	return MaxSum;
}

//分而治之
int MaxSubseqSum3(int A[], int N) {	
	int i;
	int MaxLeft, MaxRight, MaxMiddle, MaxSum = 0;
	int Left[N/2], Right[N-N/2];
	
	if (N == 1) {
		MaxSum = A[0];
		return MaxSum;
	}
	
	for (i = 0; i < N/2; i++) {
		Left[i] = A[i];
	}
	
	for (i = N/2; i < N; i++) {
		Right[i-N/2] = A[i];
	}	
	
	MaxLeft = MaxSubseqSum3(Left, N/2);
	MaxRight = MaxSubseqSum3(Right, N-N/2);
	
	int Max1 = A[N/2];
	int Max2 = A[N/2 - 1];
	int ThisSum = 0;
	for (i = N/2; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > Max1) {
			Max1 = ThisSum;
		}
	}
	ThisSum = 0;
	for (i = N/2 - 1; i >= 0; i--) {		
		ThisSum += A[i];
		if (ThisSum > Max2) {
			Max2 = ThisSum;
		}
	}	
	MaxMiddle = Max1 + Max2;
	
	MaxSum = MaxMiddle;
	if (MaxLeft>MaxMiddle && MaxLeft>MaxRight) {
		MaxSum = MaxLeft;
	}
	if (MaxRight>MaxMiddle && MaxRight>MaxLeft) {
		MaxSum = MaxRight;
	}
	
	return MaxSum;
} 
