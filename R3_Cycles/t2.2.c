

#include <stdio.h>

int main(){

 int n,i;
 double x,y,t,t1;

 // 2a

 y= 1;
 t= 1; // x^i
 n=5;
 x=2;
 t1 =x; 
 for(int i=1;i<=n;++i){
  
  t *= x;
  /* 2d
  t1 *=x*x; 
  t *= t1;

  */
  y +=t;


 } 

 printf("y=",y);

}
