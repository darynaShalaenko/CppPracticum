
#include <stdio.h>
#include <limits.h>

#include <math.h>

// returns max divisor of x in form 2^k
// or simply last 1th of x
unsigned max_pow2_div(unsigned x) {
    unsigned k=0;
    unsigned p=1;
    if(x==0) return 0;
    while(p<=x){
       if(x%p==0){k++; p<<=1;}
       else break; 
    }
    return p/2;
}

// returns 0 if x=2^k, 1 - in another cases
unsigned is_power2(unsigned x) {
    unsigned k=0;
    unsigned p=1;
    while(p<=x){
       if(x%p==0){k++; p<<=1;}
       else break; 
    }
 
    //unsigned q = (unsigned)round(log2(x));      
    // unigned t = (unsigned)pow(2,q);     
    // return  t==x;
    return (p/2==x)?0:1;
}


int main(){
   //unsigned x;
/*
   for(x=0;x< UINT_MAX;++x){
      unsigned y = (x & (x-1))?0:1;
      unsigned z = x & (-x);
      //printf("%u %u\n",z, max_pow2_div(x)); 
      //printf("z=%u %u\n",(y==0)?1:0, f2(x)); 
      if(z!=f1(x)){
          printf("Fail z for x=%x: z=x& -x =%u, f1=%u\n",x, z, f1(x)); 
      } 
      if(y!=is_power2(x)){
          printf("Fail y for x=%x: y=x& (x-1) =%u, f2=%u\n",x, y, is_power2(x)); 
      } 
      //printf("x=%x y=%x z=%x \n",x,y,z);
   }
  */

   int x1;

   for(x1=INT_MIN;x1< INT_MAX;++x1){
      int y = (x1 & (x1-1))>0;
      int z = x1 & (-x1);
      //printf("%u %u\n",z, max_pow2_div(x)); 
      //printf("z=%u %u\n",(y==0)?1:0, f2(x)); 
      int q= max_pow2_div(x1);
      if(z!=q){
          printf("Fail z for x=%x: z=x& -x =%u, f1=%u\n",x1, z, q); 
      } 

      if(y!=is_power2(x1)){
          printf("Fail y for x=%x: y=x& (x-1) =%u, f2=%u\n",x1, y, is_power2(x1)); 
      } 
      //printf("x=%x y=%x z=%x \n",x,y,z);
   }

}
