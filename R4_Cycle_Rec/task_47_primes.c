#include <stdio.h> 
#include <math.h>  

#include <stdbool.h> 

int main() { 
 int n, x; 
 int i, j, k; 
 printf("n="); 
 scanf_s("%d", &n); x = n * 2; 
 for (i = 2; i <= x; i++) { 
   k = 0; 
   for (j = 2; j <= (int)sqrt(i)+1; j++) {  // 2..sqrt(i)  //while(j<sqrt(i) && k==0) {j++;if (i % j == 0) { k=1;}}
      if (i % j == 0) { k++; 
          break;
      } 
   } 
   if (k == 0) { printf("%d\n", i); } 
  } 

}


bool isPrime(int x){
 if (x<=1) return false;

 bool k= true; 
 j=2;
 while(j<sqrt(i) && k) {
  
   if (i % j == 0) { k=false;}} 
    j++;   
   } 
    
  } 

 return k;
}
