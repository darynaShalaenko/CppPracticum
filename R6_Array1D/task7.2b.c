#include <stdio.h>
int main()
{
	
	float x;
	scanf_s("%f", &x);
	int a[5] = { 4 , 3 , 5 , 6 , 8 };
	int i = 0;
	int k = 0;
	while (i < 5) {
		if (a[i] >= x) k = k;
		else k += 1;
		i += 1;
	}
	printf("num of el %d", k);
	getchar();
	getchar();

}
