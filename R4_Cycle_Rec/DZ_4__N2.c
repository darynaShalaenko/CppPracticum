#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int sign, sign2, cnt, i;
	int arr[1000];
	sign = 0;
	cnt = 0;
	i = 0;

	while (arr[i]!=0)
	{
		printf("enter element: ");
		scanf("%d", &arr[i]);
		if (arr[i]!=0)
		{
			sign2 = arr[i] / (abs(arr[i]));
		}
		if (sign!=sign2)
		{
			sign = sign2;
			cnt++;
		}
	}
	printf("\ncount of the sign changes: %d", cnt-1);
}