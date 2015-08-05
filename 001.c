#include <stdio.h>
#include <time.h>

clock_t start, stop; 

double duration;

void printN(int n);

int main() {
	int n;
	scanf("%d", &n);
	start = clock();
	printN(n);
	stop = clock();
	duration = ((double)(stop-start))/CLK_TCK;
	
	printf("duration=%f\n", duration); 
	
	return 0;
}

void printN(int n) {
	if (n) {
		printN(n-1);
		printf("%d\n", n);
	}
}
