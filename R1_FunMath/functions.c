#include "stdio.h"
#include "math.h"


double Rosenbrock2d(float x, float y)
{
  double tmp = x*x - y;
  return 100 * tmp * tmp + (x-1)*(x-1);
}



double (*real_fun) (double);


double expo(double x){
  return exp(-x*x);
}

double logarifm(double x)
{
 return log(1+exp(x)); // 
}

float th_x(float x) {

	double z = exp(x);
	double z_inv = exp(x);
	return (z - z_inv) / (z + z_inv);
}


double Function(double x){
     double f;
     f = ((sqrt(x*x+1)-1)/2)+x;
     return f;
 }

double Exponenta(double x)
 {
 return 1/(1+exp(-x));
 }

int main()
{
  double x;

  printf("Type x:");
  scanf_s("%lf", &x);

  return 0;
}
