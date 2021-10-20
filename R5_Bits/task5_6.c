#include <stdio.h>
#include <stdint.h>

int main ()
{
  uint64_t n;
  printf("n = ");
  scanf("%llu", &n);
  int counter = 0, max_counter = 0;
  while (n>0) {
     if (n&1 == 1) {
         counter += 1;
     } else {
          if (counter > max_counter) {
             max_counter = counter;
             counter = 0;
     n = n
     n = n >> 1;
     printf("%llu", n);
     }}
  }
  printf("%d", counter);
}
