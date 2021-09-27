#include <stdio.h>
#include <math.h>


int main()
{
	int x, n;
	scanf("%d", &n);
	scanf("%d", &x);

	int k = 1;
	int s = 1;
	while (k < (n+1)) {
		s += pow(x,pow(2,k));
		k += 1;
	}
	printf("summa %d\n ", s);
	getchar();
	getchar();

}
