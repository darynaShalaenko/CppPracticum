// classwork 12: 1.a, 1.b

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

void rwr(FILE *f, FILE *g);

int main()
{
  FILE *f;  FILE *g;
  f = fopen("cw12-F.txt", "r");
  g = fopen("cw12-G.txt", "w");
  rwr(f, g);
}

void rwr(FILE *f, FILE *g)
{

  char arr[N];

  while (fgets(arr, N, f) != NULL)
  {
    for (size_t i=0; i < strlen(arr); i++)
    {
      if (arr[i] >= 'A' && arr[i] <= 'Z')
      {
        arr[i] -= 'A' - 'a';
      }
    }
    fputs(arr, g);
  }

  fclose(f);
  fclose(g);
}
