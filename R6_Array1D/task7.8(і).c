#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define N 10

int main()
{
	unsigned int arr[N];
	int res = 0, cnt = 0;

	for (int i = 0; i < N; i++)
	{
		printf("Enter arr[%d] = ", i);
		scanf("%u", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (; arr[i]; cnt++)
		{
			arr[i] &= (arr[i] - 1);
		}
		if (cnt==5)
		{
			res++;
		}
	}

	printf("\nresult = %d", res);
}