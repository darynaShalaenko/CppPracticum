#include <stdio.h>
#include <string.h>
#define N 100


int check(char* s)
{
  int sq_o = 0, sq_c = 0;
  int rnd_o = 0, rnd_c = 0;
  int fg_o = 0, fg_c = 0;
  int res = 0;

  for (int i = 0; i < strlen(s); i++)
  {
    if (s[i] == '[')
    {
      sq_o++;
    }
    if (s[i] == ']')
    {
      sq_c++;
    }
    if (s[i] == '{')
    {
      fg_o++;
    }
    if (s[i] == '}')
    {
      fg_c++;
    }
    if (s[i] == '(')
    {
      rnd_o++;
    }
    if (s[i] == ')')
    {
      rnd_c++;
    }
  }

  if (sq_o == sq_c && fg_o == fg_c && rnd_o == rnd_o)
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