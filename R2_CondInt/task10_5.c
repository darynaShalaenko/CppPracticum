#include <stdio.h>
#include <inttypes.h>

void mult_short(int16_t x, int16_t y){

   int z1 = x*y;
   int16_t z = (int16_t)z1;
   if(z==z1) {
      printf("z=%d\n",z);
   }
   else{
      printf("Overflow:");
      printf("z=%d z1=%d \n",z, z1);
   }
}

int main(){

 int16_t x,y,z; // short
 x=2; y=4;
 mult_short(x,y); 

 x=1<<15; y=1<<14+1;
 mult_short(x,y);

 scanf("%hd %hd",&x,&y);
 mult_short(x,y);
}
