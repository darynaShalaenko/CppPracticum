
#include <stdio.h>
#include <stdint.h>

uint16_t short_mult(uint8_t x, uint8_t y){
    return x*y;
}

int main(){

  uint8_t x,y;
  printf("x,y:\n");
  scanf("%hhu %hhu",&x,&y); 
  printf("x=%u,y=%u", x,y); 
  uint16_t z = short_mult(x,y);

  printf("z=%hu",z);
}

