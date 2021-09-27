#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	unsigned int M, i, j, result=0;
	unsigned arr[32];
	unsigned tmp1, tmp2;

	printf("Enter M = ");
	scanf("%u", &M);
	printf("Enter i and j, using coma: ");
	scanf("%u,%u", &i, &j);

	for (int i = 0; i < sizeof(M)*8; i++)
	{
		arr[i] = M & 1;
		M = M >> 1;
	}

	tmp1 = arr[i];
	tmp2 = arr[j];
	arr[i] = tmp2;
	arr[j] = tmp1;

	for (int i = sizeof(M)-1; i >=0; i--)
	{
		result += arr[i] * (unsigned)(1 << i);
	}

	printf("Result is %u", result);
}