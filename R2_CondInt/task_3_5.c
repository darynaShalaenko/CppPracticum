
#include <stdio.h>

int main(){
   unsigned n,m;

   printf("Input 2 unsigned numbers n,m:");
   scanf("%u %u", &n,&m);

   // 1 version
   if(n>m){
     printf("n is greater then m\n");
   }
  else {
     printf("m is greater then n\n");
  }

  // 2 version
  printf("\n %s is greater then %s",n>m?"n":"m",n>m?"m":"n");
}
