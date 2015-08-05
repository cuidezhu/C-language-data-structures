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
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d\n", i);
	}
}


