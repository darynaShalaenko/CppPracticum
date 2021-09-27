
// task 4.2

#include <stdio.h>

int main(){

   unsigned N;
   unsigned k;

   printf("N,k:");

   scanf("%u",&N);
   scanf("%u",&k);

   N = N | (1<<k); // 

   printf("M=%u",N);


}

/*

9 = 8 + 1 = 1001 (binary)
k=1 => 1011 = 8 + 2 +1 =11


*/

 
 
