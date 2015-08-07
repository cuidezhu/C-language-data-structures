//多项式的值 

#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAXN 10		//多项式最大项数，即多项式阶数+1 
#define MAXK 1e7

clock_t start, stop;
double duration;

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main() {
	int i;
	double a[MAXN];		//储存多项式的系数 
	for (i = 0; i < MAXN; i++) {
		a[i] = (double)i; 
	}
	
	start = clock();
	for (i=0; i<MAXK; i++) {
		f1(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = ((double)(stop-start))/(CLK_TCK*MAXK);
	printf("ticks1=%f, CLK_TCK=%d\n", (double)(stop-start), CLK_TCK);
	printf("duration1 = %6.2e\n", duration); 
	printf("f1(MAXN-1, a, 1.1)=%f\n", f1(MAXN-1, a, 1.1));
	
	start = clock();
	for (i=0; i<100000; i++) {
		f2(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = ((double)(start-stop))/(CLK_TCK*MAXK);
	printf("ticks2 = %f, CLK_TCK=%d\n", (double)(stop-start), CLK_TCK);
	printf("duration2 = %6.2e\n", duration);
	printf("f2(MAXN-1, a, 1.1)=%f\n", f2(MAXN-1, a, 1.1));	
	return 0;
}

double f1(int n, double a[], double x) {
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++) {
		p += (a[i] * pow(x, i));
	}
	
	return p;
}

double f2(int n, double a[], double x) {
	int i;
	double p = a[n];
	for (i = n; i > 0; i--) {
		p = a[i-1] + p*x;
	} 
	
	return p;
}

