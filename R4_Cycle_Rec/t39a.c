#include <stdio.h> 
//#include <math.h> 
int main(){ 
 int a1 = 0, a2 = 1, ak, n, sum=a1+2*a2;

 int t = 4; 
 scanf("%d",&n); 
 for (int k = 3;k<=n;k++){ 
  ak = a2 + k*a1; 
  a1=a2; 
  a2=ak; 
  t *=2; // t == 2**k
  

  sum += t*ak;
 } 
 printf("%d",sum); 

} 
