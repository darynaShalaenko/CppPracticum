// Bad solution to the problem
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>



static int fct(int n)
{
	return (n < 2) ? 1 : n * fct(n - 1);
}

int main()
{
	double eps, s=0, elem, x;
	bool exit = false;
	int i = 0;
	printf("enter epsilon: ");
	scanf("%lf", &eps);
	printf("enter x: ");
	scanf("%lf", &x);
	while (exit==false)
	{
		elem = pow(x, 2 * i) / (fct(i));
		printf("elem = %lf\n", elem);
		if (fabs(elem)>=eps)
		{
			s = s + elem;
		}
		else
		{
			exit = true;
		}
		i++;
	}
	printf("s = %lf", s);
}
