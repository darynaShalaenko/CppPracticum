#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* F1(char*s1, char*s2, int k)
{

    int n1 = strlen(s1);
    int n2 = strlen(s2);

    int n = n1+n2;
    char *s = (char*)malloc(n);

    for (int i = 0; i < k; i++)
    {
        s[i] = s1[i];
    }

    for (int j = 0; j < n2; j++)
    {
        s[j+k] = s2[j];
    }

    for (int t = 0; t < n1; t++)
    {
        s[t+k+n2] = s1[t+k+1];
    }

    return s;
}



int main()
{
int k = 3;
char s1[31] = "";
char s2[31] = "";
printf("s1 = ");
scanf("%s", s1);

printf("\ns2 = ");
scanf("%s", s2);

printf("\nk = ");
scanf("%d", &k);

if (k > strlen(s1))
{
    k = strlen(s1);
}

char* res = F1(s1, s2, k);
printf("\n%s", res);

free(res);
}