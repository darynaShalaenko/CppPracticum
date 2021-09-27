
#include <stdio.h> 
/*
2+31; 45*54-11; 15/4; 15.0/4; 67%5; (2*45.1 +3.2)/2;
*/
int main() {
 int a = 2; 
 int b = 31; 
 printf("sum = %d\n", a+b);
 printf("vyraz = %d \n", 45*54-11) ;

 printf("dilennya = %d, %lf , %d \n", 15/4, 15.0/4, 67%5) ;

 double r1 = (2*45.1 +3.2)/2;

 printf("r1=%lf", r1);
 return 0; 
} 
