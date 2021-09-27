#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100


  int check(char* arr)
  {
      int res = 0;
      int k = -1, m = 0, r = 0;
      char example[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

      for (int i = 0; i < strlen(arr); i++)
      {
        for (int j = 0; j < strlen(example) + 1; j++)
        {
          if (arr[i] == example[j] && k == -1)
          {
            k = j;
            r = j;
          }
          if (arr[i] == example[j] && k != -1 && j == r + 1)
          {
            r++;
          }
          else
          {
            m = r;
          }
        }
      }
      if (strlen(arr) == m - k + 1)
      {
        res = 1;
      }

      return res;
  }

int main()
{
  char* str = malloc(sizeof(char) * N);

  printf("type string: ");
  gets(str);

  if (check(str))
  {
    printf("0123456789 include %s", str);
  }
  else
  {
    printf("0123456789 dont include %s", str);
  }

  return 0;
}