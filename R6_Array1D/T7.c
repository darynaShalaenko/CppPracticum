/*
Вводиться масив натуральних чисел заданого розміру N:
б) визначити скільки серед цих чисел парних повних кубів
*/

#include <stdio.h>
#include <math.h>
#include <stdint.h>
# define N 100


void inp_arr(int x[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Type element %d: ", i + 1);
    scanf("%u", &x[i]);
  }
}


int func(int x[], int n)
{
  int res = 0;

  for (size_t i = 0; i < n; i++)
  {
    if (x[i] % 2 == 0)
    {
      if ((int64_t)(pow(x[i], 1/3)) == (pow(x[i], 1/3)))
      {
        res += 1;
      }
    }
  }

  return res;
}

int main()
{
  int a[N];
  int n;

  printf("Type n:");
  scanf("%d", &n);

  inp_arr(a, n);
  printf("%d\n", func(a, n));

  return 0;
}
