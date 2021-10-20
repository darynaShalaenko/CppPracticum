#include <stdio.h>
#include <string.h>
#define N 100


int symmetrical(char* s)
{
  char s2[N];
  strncpy(s2, s, N);  //copy s to s2
  strrev(s2);
  return strcmp(s, s2);
}


char* revers(char* s)
{
  return strrev(s);
}


int main()
{
   char s[N];

   printf("Enter a string to reverse: ");
   gets(s);

   printf("Reverse of the string: %s\n", revers(s));

   if (symmetrical(s) == 0)
   {
     printf("String is symmetrical");
   }
   else
   {
     printf("String is not symmetrical");
   }

   return 0;
}