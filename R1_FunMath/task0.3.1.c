
#include <stdio.h>
#include <math.h>

double task_03_1a(double x){
   double y = x*x + 1; // x^2 + 1
   return y*y; // (x^2+1)^2 = x^4 + 2*x^2 + 1
}


double task_03_2a(double x,double y){
   double z = x + y;
   return z*z*z; 
}

int main(){
  double x,y;

  scanf("%lf",&x);


  if(fabs(task_03_1a(0)-1.0)>0.00001){
     printf("Error in function at x=0");
  } 

  if(fabs(task_03_1a(-2)-25.0)>0.00001){
     printf("Error in function at x=-2");
  } 

  y = task_03_1a(x);
  printf("y=%lf",y);

  if(fabs(task_03_2a(0,0)-0.0)>0.00001){
     printf("Error in function2 at x=0,0");
  } 

  if(fabs(task_03_2a(-2,2)-0.0)>0.00001){
     printf("Error in function2 at x=-2,2");
  } 

  if(fabs(task_03_2a(2,2)-16.0)>0.00001){
     printf("Error in function2 at x=-2,2");
  } 



}
