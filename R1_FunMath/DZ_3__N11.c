#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, z, R;
	printf("enter x: ");
	scanf("%lf", &x);
	printf("enter y: ");
	scanf("%lf", &y);
	printf("enter z: ");
	scanf("%lf", &z);
	printf("enter R: ");
	scanf("%lf", &R);
	if (pow(x,2)+pow(y,2)+pow(z,2)<=pow(R,2))
	{
		printf("tochka nalejyt kuli");
	}
	else
	{
		printf("tochka ne nalejyt kuli");
	}
	
}