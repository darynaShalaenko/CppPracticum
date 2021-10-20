
#include <stdio.h>

unsigned seq_bits(unsigned n){

  unsigned i = 1u; 
  unsigned r=0;
  unsigned max_r =0;
  //unsigned k=0;
  for(;i<=n;i<<=1){
      if(i & n){ // log(i)-th bit
         r++;
         //printf("%u %u %u",i,r,k);
      } 
      else{
        if(max_r<r) {
          max_r =r; 
        }
        r = 0;
      }
      
  }
  return max_r;
}

int main(){
   unsigned n;
   printf("n=");
   scanf("%u",&n);	

   printf(" number of nonzero sequantial bits in %x is %u",n,seq_bits(n)); 

}
