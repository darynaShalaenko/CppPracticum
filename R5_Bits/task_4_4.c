#include <stdio.h>
#include <intypes.h>

unsigned uint32_t byteReplace(uint32_t n){

unsigned res = n & 0x00FFFF00;
printf("%x %x\n",n, res);
res |= (n>>24);
printf("%x %x\n",n, res);
res |= (n<<24); 
printf("%x %x\n",n, res);
  return res;
}

unsigned byteReplace1(unsigned n){

   unsigned m= sizeof(n)*8;
   unsigned m1 = m-8;
   return ((n & 255)<<m1) | (n>>m1) | (((n>>8)<<(m1-8))>>8);
}

unsigned byteReplace2(unsigned n){
   unsigned m1 = sizeof(n)*8 -8;
   unsigned Mask1 = (1<<m1) - (1<<8);

res = n & Mask1;
printf("%x %x\n",n, res);
res |= (n>>m1);
printf("%x %x\n",n, res);
res |= (n<<m1); 
printf("%x %x\n",n, res);
return res;
}


int main(){

unsigned n;
scanf("%u",&n);


printf("%x",byteReplace(0x11223344));

printf("%x %x\n",n, byteReplace(n));



}
