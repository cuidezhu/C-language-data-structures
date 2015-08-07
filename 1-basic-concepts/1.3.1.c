//最大子列和问题
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

//分而治之,算法的时间复杂度为O(NlogN)
int MaxSubseqSum3(int A[], int N) {	
	int i;
	int MaxLeft, MaxRight, MaxMiddle, MaxSum = 0;
	int Left[N/2], Right[N-N/2];		/*把这个数组分为左右两个数组,声明这两个数组 */
	
	if (N == 1) {						/*递归结束条件*/
		MaxSum = A[0];
		return MaxSum;
	}
	 
	for (i = 0; i < N/2; i++) {
		Left[i] = A[i];					/*为左边序列的数组赋值*/
	} 
	
	for (i = N/2; i < N; i++) {
		Right[i-N/2] = A[i];			/*为右边序列的数组赋值*/
	}	
	
	//用递归方法分别求左右序列的最大最大子序列的和 
	MaxLeft = MaxSubseqSum3(Left, N/2);
	MaxRight = MaxSubseqSum3(Right, N-N/2);
	
	//求跨过界限的序列最大值MixMiddle
	int Max1 = A[N/2];
	int Max2 = A[N/2 - 1];
	int ThisSum = 0;
	for (i = N/2; i < N; i++) {			/*求从界限向右的最大值*/
		ThisSum += A[i];
		if (ThisSum > Max1) {			
			Max1 = ThisSum;
		}
	}
	ThisSum = 0;
	for (i = N/2 - 1; i >= 0; i--) {	/*求从界限向左的最大值*/
		ThisSum += A[i];
		if (ThisSum > Max2) {
			Max2 = ThisSum;
		}
	}	
	MaxMiddle = Max1 + Max2;			/*左右两边求和即为跨过界限的序列的最大值*/
	
	//左序列，右序列，跨过界限的序列三者的最大值 
	MaxSum = MaxMiddle;
	if (MaxLeft>MaxMiddle && MaxLeft>MaxRight) {
		MaxSum = MaxLeft;
	}
	if (MaxRight>MaxMiddle && MaxRight>MaxLeft) {
		MaxSum = MaxRight;
	}
	
	return MaxSum;
} 

//在线处理算法，算法的时间复杂度为O(N)
int MaxSubseqSum4(int A[], int N) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];				/*向右累加*/ 
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;			/*发现更大和则更新当前结果*/ 
		}
		else if (ThisSum < 0) {			/*如果当前子列和为负*/ 
			ThisSum = 0;				/*则不可能使后面的部分和增大，抛弃之*/ 
		}
	}
	
	return MaxSum;
}
