#include <stdio.h>

void task1(unsigned n){

  unsigned a,b,c,s;
  if((n>=100) && (n<=999)){  // number is 3-digit
    a= n%10; // last digit
    b = (n/10)%10; // second digit
    c = n / 100; // first digit

    s = a+b+c;
    unsigned m = 100*a +10*b + c;

    printf("%u, %u, %u;  sum =%u, inversia= %u",c,b,a,s,m); 
  }
}


int main(){

  unsigned n; // unsigned int 0 - 2^32-1
  printf("n=");
  scanf("%u",&n);
  task1(n); 
}
