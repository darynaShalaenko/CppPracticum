#include <stdio.h>
#include <math.h>

double func_1a(double x){
  
     double y = x*x + 1; 
     return y*y;

}
 // (x**5-1)/(x-1) x!=1
 // (x+1)**5
 // (2*x+1)**5
 // (x**12-1)/(x**3-1) 


double Rosenbrock2D(double x, double y){
    double  z = 10*(x*x-y);
    double t = x - 1;
    return z*z + t*t;
}

int main(){

  double x;
  scanf("%lf",&x);

  if ( fabs(func_1a(1) - 4)>0.0000001){
     printf("Function is incorrect for x=1\n");
  }
 else{
    printf("func is correct for x=1\n");
 }

  if ( fabs(func_1a(-3) - 100)>0.0000001){
     printf("Function is incorrect for x=-3\n");
  }
 else{
    printf("func is correct for x=-3\n"); }

  double y = func_1a(x);
  printf("y=%lf",y);


if ( fabs(Rosenbrock2D(1,1))>0.0000001){
     printf("Rosenbrock is incorrect for x,y=1,1\n");
  }
 else{
    printf("Rosenbrock is correct for x,y=1,1\n");
 }

  if ( fabs(Rosenbrock2D(2,4) - 1)>0.0000001){
     printf("Rosenbrock is incorrect for x,y=2,4\n");
  }
 else{
    printf("Rosenbrock is correct for x=2,4\n"); }

  
  

}
