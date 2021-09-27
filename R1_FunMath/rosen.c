#include <stdio.h>
#include <math.h>

double Rosenbrock2d(float x, float y)
{
  double res = 100 * pow((pow(x, 2) - y), 2) + pow((x-1), 2);
  return res;
}

int main()
{
  float x, y;

  printf("Type x:");
  scanf("%f", &x);

  printf("Type y:");
  scanf("%f", &y);

  printf("Rosenbrock = %lf\n", Rosenbrock2d(x, y));

  return 0;
}
