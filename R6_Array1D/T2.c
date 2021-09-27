#include <stdio.h>
#include <math.h>
#define N 100

void inp_arr(double x[], int n)
{
  printf("Type coords:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &x[i]);
  }
}

void func(double x[], double y[], double z[], int n, unsigned sigma)
{
  for (int i = 0; i < n; i++)
  {
    z[i] = exp( -(pow(sqrt(pow((x[i] - y[i]), 2)), 2)) / (2 * sigma * sigma));
  }
}

void out_vec(double x[], int n)
{
  for (int i = 0; i < n; i++) {
    printf("x[%d] = %lf\n", i, x[i]);
  }
}

int main()
{
  double a[N];
  double b[N];
  double c[N];
  int n;
  unsigned sig;

  printf("Type sig");
  scanf("%u", &sig);

  printf("Type n:");
  scanf("%d", &n);

  inp_arr(a, n);
  inp_arr(b, n);
  func(a, b, c, n, sig);
  out_vec(c, n);

  return 0;
}
