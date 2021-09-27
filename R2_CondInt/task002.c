#include <stdio.h>
#include <math.h> // floor

int main(){

 double d;
 printf("Real number:");
 scanf("%lf", &d);

 double d1,d2;
 int z1; // z1 = (int)d;
 //d1 = d - z1;
 d1 = modf(d,&d2);
 printf("float part= %lf\n", d1);

 z1 = floor(d);
 printf("\ninteger part= %d or %d and for abs value %d \n", z1,(int)d, (int)d2);

 int z2 = ceil(d);
 printf("]%lf[= %d\n",d, z2); 
 int z3 = round(d);
 printf("round(%lf)= %d\n", d, z3);

}
