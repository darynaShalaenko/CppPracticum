
#include <stdio.h>
#include <math.h>

double length(double x1,double y1,double x2,double y2){
   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double square_triangle(double a,double b,double c){
   double p = (a+b+c)/2;  
   return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){

  double ax,ay,bx,by,cx,cy;
  printf("A:\n");
  scanf("%lf %lf",&ax,&ay);
  printf("B:\n");
  scanf("%lf %lf",&bx,&by);
  printf("C:\n");
  scanf("%lf %lf",&cx,&cy);

  double a = length(ax,by,bx,by);
  double b = length(bx,by,cx,cy); 
  double c = length(bx,by,ax,ay); 

  double s = square_triangle(a,b,c);
  printf("S=%lf", s);

}

