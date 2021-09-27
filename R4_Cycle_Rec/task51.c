
#include <stdio.h>

#include <math.h>


double halb_cut(double a, double b, double eps){

   if(b-a<eps) return (a+b)/2;

   double z = (a+b)/2;

   if (tan(z)-z<0) return halb_cut(z,b);  
   else return halb_cut(a,z);

}


int main(){

  double a=0.001, b= 1.5;
  double x,y, eps;

 
   do{
     printf("Input real eps>0:");
     scanf("%lf",&eps); // eps>0 
   } while(eps<=0);


   x = halb_cut(a,b,eps);  //tg(0.001) -0.001 <0,  tg(1.5)-1.5 >0 

   printf("x=%lf",x);
}


