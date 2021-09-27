#include <stdio.h>
int main()
{
	int x1, x2, y1, y2;
	int x3, x4, y3, y4;
	scanf_s("%f", &x1);
	scanf_s("%f", &y1);
	scanf_s("%f", &x2);
	scanf_s("%f", &y2);
	scanf_s("%f", &x3);
	scanf_s("%f", &y3);
	scanf_s("%f", &x4);
	scanf_s("%f", &y4);

	int xl;
	int yl;
	int xr;
	int yr;
		if (x1 <= x3)
			xl = x1;
		else
			xl = x3;

	if (y1 <= y3)
		yl = y1;
	else
		yl = y3;

	if (x2 >= x4)
		xr = x2;
	else
		xr = x4;

	if (y2 >= y4)
		yr = y2;
	else
		yr = y4;

	printf("%d\n %d\n %d\n %d\n", xl, yl, xr, yr);
	getchar();
	getchar();

	
}
