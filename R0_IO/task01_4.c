
#include <stdio.h>


int main(){
  double a,b;
  double c,d;

  scanf("%lf %lf", &a, &b);

  c = (a + b) /2;
  d = 2 / (1/a + 1/b);

  printf("average = %lf or %le \n", c,c);
  printf("harmonical = %lf or %le \n", d,d); 

}
