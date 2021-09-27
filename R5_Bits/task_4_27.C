#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int M, N;
	unsigned int arrM[32], arrN[32];
	unsigned int res_ones = 0, res_total = 0;

	printf("Enter M and N using a coma as a separator: ");
	scanf("%u,%u", &M, &N);
	for (int i = 0; i < sizeof(M)*8; i++)
	{
		arrM[i] = M & 1;
		M = M >> 1;
	}
	for (int j = 0; j < sizeof(N) * 8; j++)
	{
		arrN[j] = N & 1;
		N = N >> 1;
	}

	for (int k = sizeof(M) * 8 - 1; k >= 0; k--)
	{
		if (arrM[k] == arrN[k])
		{
			if (arrM[k] == 1)
			{
				res_ones += 1;
			}
			res_total += 1;
		}
	}

	printf("count of the ones: %u\n", res_ones);
	printf("count of the equal bits: %u\n", res_total);
}