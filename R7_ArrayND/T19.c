/*
19) У квадратній таблиці обміняйте місцями елементи рядка і стовпця,
на перетині яких знаходиться мінімальний з позитивних елементів.
*/
#include <stdio.h>
#define N 12


void inp_matr(double x[N][N], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%lf", &x[i][j]);
    }
  }
}


void change_smth(double x[N][N], int n)
{
  double temp = 1 << 31 - 1;
  int row, column;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (x[i][j] > 0)
      {
        if (x[i][j] < temp)
        {
          temp = x[i][j];
          row = i;
          column = j;
        }
      }
    }
  }

  double temp_change;
  for (size_t i = 0; i < n; i++)
  {
    temp_change = x[row][i];
    x[row][i] = x[i][column];
    x[i][column] = temp_change;
  }
}


void out_put(double x[N][N], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%lf ", x[i][j]);;

    }
    printf("\n");
  }
}

int main()
{
  double a[N][N];
  int n = 3;


  inp_matr(a, n);
  change_smth(a, n);
  out_put(a, n);

  return 0;
}
