
#include <stdio.h>

unsigned lBit(unsigned n){
   unsigned i=1u, k= 0, max = 0;
   for(int i = 0; i < 32; i++){
       if((n >> i) & 1){
           k++;
       }
       else{
           if(k > max){
               max=k;
           }
           k=0;
       }
   }
   return max;
}

int main(){
    unsigned n;
    //n=312;
    printf("n=");
    scanf("%u",&n);
    printf("%u", lBit(n));
}
