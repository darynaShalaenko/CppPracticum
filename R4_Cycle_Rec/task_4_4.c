
#include <stdio.h>

int main(){

    //int f0=0,f1=1,f;
    int x0=-99,x1=-99,x2=-99,x;
    int N = 0;
    int k = 2;
    while(x2<N){
       //f = f0 + f1;
       x = x0 + x2 + 100;
       k++;
       //f0= f1;       f1 =f;
       x0 = x1;
       x1 = x2;
       x2 = x;
    }	

   printf("The first Tribonacci number greater then %d is x(%d)=%d",N,k,x2);

}
