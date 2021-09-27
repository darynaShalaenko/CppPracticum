#include<stdio.h>
int main() {
	float x;
	printf("input x = \n");
	scanf_s("%g", &x);
	x = x * x * x;
	x = x * x * x;
	printf("x^9 = %g", x);
}
