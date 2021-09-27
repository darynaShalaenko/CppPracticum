
#include <stdio.h>
//b
int harm_less(double a){

   double s = 0.0; // s =1 +1/2 +... 
   int i=1;
   while(s<a){
     s += 1.0/i;
     i++; 
     printf("s=%lf",s);
   } 
   return i-1;
}

int harm_less1(double a){

   double s = 0.0; // s =1 +1/2 +... 
   int i=1;
   while(s<a){
     s += 1.0/i;
     i++; 
     printf("s=%lf",s);
   } 
   return s;
}

int main(){

  double a;
  printf("a=");
  scanf("%lf",&a);

  printf("n=%d s=%lf",harm_less(a),harm_less1(a));
}
