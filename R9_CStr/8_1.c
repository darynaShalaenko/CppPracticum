#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* function(char* s)
{
	int n = strlen(s);
	char* s1 = (char*)malloc(2*n);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i]!='*')
		{
			s1[j] = s[i];
			s1[j + 1] = s[i];
			j += 2;
		}
	}
	return s1;
}


int main()
{
	char s[31] = "";
	printf("Enter a string:\n");
	printf("s = ");
	scanf("%s", &s);

	char* result = function(s);
	printf("Results: %s", result);
	free(result);
}