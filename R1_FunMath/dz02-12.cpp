#include <stdio.h>
#include <math.h>
int main()
{
	
	float d, z, x , a, b, c;
	scanf_s("%f %f %f", &a, &b, &c);
	d = b*b - (4 * a*c);
	x = (-b + sqrt(d)) / (2 * a);
	z = (-b - sqrt(d)) / (2 * a);
	printf(" x1 is %f\n x2 is %f\n", x, z);
	getchar();
	getchar();

	return 0;
}
