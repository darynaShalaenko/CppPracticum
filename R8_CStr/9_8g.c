#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100


int check(char* s)
{
  int count = 0;
  int res;

  for (size_t i = 0; i < strlen(s); i++)
  {
    if(isdigit(s[i]))
    {
      count += (int)s[i] - 48;
    }
  }

  if (count == strlen(s))
  {
    res = 1;
  }
  else
  {
    res = 0;
  }

  return res;
}


int main()
{
   char* s = malloc(sizeof(char) * N);

   printf("Enter a string to reverse: ");
   gets(s);

   if (check(s) == 1)
   {
     printf("ok");
   }
   else
   {
     printf("not ok");
   }

   return 0;
}