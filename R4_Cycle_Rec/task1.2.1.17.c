#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double my_sinus(double x, double eps){
 double a,y;
  int k=0;

  a = 1.0; 
  y = a;
  while(fabs(a)>eps){
     k++;
     a = a * (-x) * k*k / (k+1)/(k+1); // 1, -x/1^2, x^2/3^2, .....
     y += a;
     
 }
}



int main(){

  double x,eps;
 

  do{
    printf("x=");
    scanf("%lf",&x);
  } while(false);


  do{
    printf("eps(eps>0)=");
    scanf("%lf",&eps);
  } while(eps<0.00001);



  printf("y=%lf",my_sinus(x,eps));

}
