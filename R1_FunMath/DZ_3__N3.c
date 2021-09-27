
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	long int a, b, c, res;
	printf("enter three numbers ");
	scanf("%d,%d,%d", &a, &b, &c);
	long int e1, e2;
	e1 = pow(2,10);
	e2 = pow(2,21);
	if (abs(a+b+c)<e1)
	{
		res = a * b * c;
		printf("1) dobutok = %d\n", res);
	}
	if (abs(a + b + c) < e2)
	{
		res = a * b * c;
		printf("2) dobutok = %d", res);
	}
}
