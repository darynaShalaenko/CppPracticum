#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float x1, x2, y1, y2;
	scanf("x1 = %f", &x1);
	scanf("x2 = %f", &x2);
	scanf("y1 = %f", &y1);
	scanf("y2 = %f", &y2);
	printf("%f %f %f %f", x1, x2, y1, y2);
	getchar();
}