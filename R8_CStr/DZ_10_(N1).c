#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* function1(char* s1, char* s2, int k)
{
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	char* s = (char*)malloc(k+n2);
	for (int i = 0; i < k; i++)
	{
			s[i] = s1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		s[i + k] = s2[i];
	}
	return s;
}

char* function2(char* s1, char* s2, int k)
{
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	for (int i = 0; i < n2; i++)
	{
		s1[i + k] = s2[i];
	}
	return s1;
}

int main()
{
	int k;
	char s1[31] = "";
	char s2[32] = "";
	printf("Enter the values:\n");
	printf("s1 = ");
	scanf("%s", &s1);
	printf("s2 = ");
	scanf("%s", &s2);
	printf("k = ");
	scanf("%d", &k);

	if (k>strlen(s1))
	{
		k = strlen(s1);
	}
	char* result1 = function1(s1, s2, k);
	char* result2 = function1(s1, s2, k);
	printf("Results:\n1) %s", result1);
	printf("\n2) %s", result2);
	free(result1);
	free(result2);
}