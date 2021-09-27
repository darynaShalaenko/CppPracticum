
// task 4.3

#include <stdio.h>

int main(){


   unsigned long long M; // 63

   unsigned j; //<64           // 4  
   printf("Input M and j:\n");
   scanf("%Lu",&M);
   scanf("%u",&j);
   
   M = M & ~(1<<j); 
   
   printf("M = %Lu %Lo %Lx", M, M, M);
}

