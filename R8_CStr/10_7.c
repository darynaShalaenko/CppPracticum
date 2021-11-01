#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* change(char*s0)
{
    int n = strlen(s0);
    char *s1 = (char*)malloc(n);
    int i = 0;
    while (s0[i] != '.')
    {
        if (s0[i] == ',')
        {
          s1[i] = ' ';
        }
        else
        {
          s1[i] = s0[i];
        }
        i++;
    }
    for (int j = i; j < n; j++)
    {
      if (s0[j] == '3')
      {
        s1[j] = '+';
      }
      else
      {
        s1[j] = s0[j];
      }
    }
return s1;
}



int main()
{
char s0[31] = "";
scanf("%s", s0);

char* res = change(s0);
printf("%s", res);
free(res);

}