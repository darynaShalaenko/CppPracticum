#include <stdio.h>
int main()
{
	float s = 0;
	int n;
	float a;
	scanf_s("%d", &n);
	int i = 0;
	while (i < n) {
		scanf_s("%f", &a);
		if (a<10 && a >1) s += a;
		else s += 1;
		i += 1;
	}
	printf(" summa %d\n", s);
	getchar();
	getchar();

}
