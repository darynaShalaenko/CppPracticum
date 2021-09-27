#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	unsigned M;
	unsigned result = 0;
	int arr[32];

	printf("Enter a number M = ");
	scanf("%u", &M);
	for (int i = sizeof(M)*8-1; i>=0; i--)
	{
		arr[i] = M & 1;
		M = M >> 1;
	}
	printf("Reversed number:\n   binary: ");
	for (int i = sizeof(M) * 8 - 1; i >= 0; i--)
	{
		printf("%u", arr[i]);
	}
	for (int i = sizeof(M) * 8 - 1; i >= 0; i--)
	{
		result += arr[i] * (unsigned)(1 << i);
	}
	printf("\n   decimal: %u", result);
}