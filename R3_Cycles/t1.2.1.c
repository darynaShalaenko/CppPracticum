// task 1.2.1

#include <stdio.h> 
#include <math.h>

int main() { 
 double x; int n; 
 printf("Enter x = "); 
 scanf("%lf",&x); 
 printf("Enter n = "); 
 scanf("%d", &n);
 
 for (int i = 0; i < n; i++) { 
       x = sin(x); 
  } 
 printf( "x = %lf \n", x); 
 getchar();

}
