
// task 1.2.38

#include <stdio.h>

int main(){

   int i,n,k;

   float u0=0.0f,u1=0.0f,un,v0=1.0f,v1=1.0f,vn;

   printf("n=");
   scanf("%d",&n);

   for(i=2;i<=n;++i){

      un = (u1 - u0 * v1 - v0)/ (1 + u1 * u1 + v1*v1);

      vn = (u1 - v1) / (fabs(u1+v1) + 2);

      u0 = u1;
      u1 = un;

      v0 = v1;
      v1 = vn;

  }
  
  printf(" v(%d)=%f ", n, vn);
  

}


