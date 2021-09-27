#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double x, f;
	printf("enter x: ");
	scanf("%lf", &x);
	f = fmax(0, x);
	printf("f = %lf", f);
}