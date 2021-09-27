#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 5

int main()
{
	char array[N], new_array[N];
	int k = 1;
	printf("Enter a string: ");
	scanf("%s", &array);

	new_array[0] = array[0];
	for (int i = 1; i < N+1; i++)
	{
		if (array[i] == 'b')
		{
			if (array[i-1]!='c')
			{
				new_array[k] = array[i];
				k++;
			}
		}
		else
		{
			new_array[k] = array[i];
			k++;
		}
	}
	printf("Result: ");
	printf("%s", new_array);
}