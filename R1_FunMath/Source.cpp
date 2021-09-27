//Hw1 №0.2.3
/*Умова:
 Обчислити площу трикутника S за трьома сторонами a, b, c.
*/

#include <stdio.h>
#include <cmath>

int main()
{
	float S, p, a, b, c;
	printf("a = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("c = ");
	scanf_s("%f", &c);
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("S = %g\n", S);
}