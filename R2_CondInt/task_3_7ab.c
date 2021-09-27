

#include <stdio.h>
#include <float.h> // DBL_EPSILON, DBL_MAX
#include <math.h> //fabs,sqrt
#include <stdbool.h> // bool type


bool isNearlyZero(double x){
   return fabs(x)<0.000001; //2*DBL_EPSILON); //  fabs(x) =|x|
}

bool isNearlyEqual(double x, double y){
   return (fabs(x-y)<= DBL_EPSILON* 2*(fabs(x) + fabs(y)));
}

void selectSqrRoot(double x){
   if (isNearlyZero(x)){
      printf("x=%lf\n",0.0); 
   }
   else if(x>0){
     double z = sqrt(x);
     printf("roots %lf and %lf\n",z, -z);
   }

}

int main(){

  double a,b,c;
  double D,x1,x2;
  printf("Input a b c:\n");
  scanf("%lf %lf %lf",&a, &b, &c);


  if(isNearlyZero(a)){

    if(isNearlyZero(b)){
       // a=b=c=0
      if(isNearlyZero(c)){
         printf("All real numbers");
         return 0;
      }
      //a=b=0 c<>0
      printf("No solutions");
      return 0;     
    }
    // a=0, b<>0     
    else{
      x1 = -c/b; 
      //printf("Only solution x1=%lf",x1);
      selectSqrRoot(x1);
    }
    return 0;
  }
  // a<>0
  D = b*b - 4*a*c;

  if(isNearlyZero(D)){
    x1 = -b/2/a; 
    //printf("Only solution x1=%lf",x1);
     selectSqrRoot(x1);
  }
  else if(D>0){
    x1 = (-b-sqrt(D))/2/a; 
    x2 = (-b+sqrt(D))/2/a;
    //printf("Two solutions %lf and %lf",x1,x2);
    selectSqrRoot(x1);
    selectSqrRoot(x2);
  }
  else{
      printf("No solutions");
  }     
   

}
