
#include <stdio.h>
#include <math.h>
double Square(double a, double b, double c){
   double p = (a + b + c)/2;
   return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
  double a,b,c;
  scanf("%lf %lf %lf", &a,&b,&c);
  double s = Square(a,b,c);
  printf("S=%lf",s); 

}
