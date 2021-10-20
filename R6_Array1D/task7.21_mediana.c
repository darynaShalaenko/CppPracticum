#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

int main() {
	int a[N];

	for (int i = 0; i < N; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	int a_min = a[0], a_max = a[0];
	for (int i = 1; i < N; i++)
	{
		if (a[i]<a_min)
		{
			a_min = a[i];
		}
		if (a[i] > a_max)
		{
			a_max = a[i];
		}
	}

	int a_avg;
	a_avg = (a_min + a_max) / 2;

	int med = a[0], df = abs(a_avg - a[0]);
	for (int i = 1; i < N; i++)
	{
		if (abs(a_avg - a[i])<df)
		{
			med = a[i];
			df = abs(a_avg - a[i]);
		}
	}

	printf("Mediana = %d", med);
}