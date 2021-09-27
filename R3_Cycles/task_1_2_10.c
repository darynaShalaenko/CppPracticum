
// task 1_2: 10)

#include <stdio.h> 
//#include <math.h> 

int main() { 

 float ans, m, k; 
 printf("m="); 
 scanf_s("%g", &m); 
 k = 0;
 ans =1;  
 while ( ans<= m) { k++; ans *= 4;}
 printf("k=%g", k-1); 
} 
