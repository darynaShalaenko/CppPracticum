
/* Експонента за тейлором точністю e>0, task 45 d) */

#include <stdio.h>
#include <math.h>

int main(){

   double x, eps; // input
   double t,y;
   int i;
   printf("Input real x=");
   scanf("%lf",&x);
  
   do{
     printf("Input real eps>0:");
     scanf("%lf",&eps); // eps>0 
   } while(eps<=0);

   t = 1; // x^i/i!
   i = 0;
   
   y = 1; // y =exp(x)
   
   while(fabs(t) > eps){
      i++;
      t *=  x / i; // x^i/i! 
      y += t;
   }

   printf("y=%lf",y);
   printf("exp(x)=%lf",exp(x));
}
