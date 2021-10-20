
// C style program : task0.pdf - task1.c
#include <stdio.h>
 // 15/4; 15.0/4; 67%5; (2*45.1 +3.2)/2;
int main(){
  
   int x,y; // integer variables x,y
   x = 45;
   y = 54;  // 45*54-11
   int z;
   z = x*y - 11;  // +, -, *, /
   
   double z1 = (double)y/x; // real number types: float, double, long double
   printf("%lf", z1);
  
   printf("%lf %lf ", 15/4, 15.0/4);
   printf("%lf ", 15.0/4);
   printf("%d ", 67%2); // % - остача від ділення

}




