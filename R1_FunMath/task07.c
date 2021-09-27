

#include <stdio.h>
#include <math.h>

int main(){
   double x;
   scanf("%lf",&x);

   // [x]
   int z1 = (int)x; // integer
 
   if(x<0){
       z1--; 
   }
   printf("z=%d\n",z1);

   // floating part

   double fp = x - z1;
   printf("fp=%lf\n",fp);

  // ]x[  - minimal integer, greater then x
  int z2 = (int)x; // integer
 
   if(x>0){
       if(fp>0)
        z2++; 
   }
   printf("z2=%d\n",z2); 

   //using math
   z1 = floor(x); // [x]
   z2 = ceil(x); //]x[
   int z3 = round(x);
   fp = x -z1;

   printf(" [%lf] = %d, ]%lf[=%d, round=%d, fp= %lf \n", x,z1,x,z2,z3,fp);
}
