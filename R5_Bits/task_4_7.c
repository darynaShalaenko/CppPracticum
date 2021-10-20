#include <stdio.h>


int main() { 

/*
N = 1 byte | 2 byte | 3 byte | 4 byte

N = 4 byte | 3 byte | 2 byte | 1 byte

N   = 00001.. | 00.. | ... | ....

    a1 * 8^3 +  a2 * 8^2 + a3 *8 + a4 // little

    a4 * 8^3 +  a3 * 8^2 + a2 *8 + a1 // big 

    a1 * 8^3 +  a3 * 8^2 + a2 *8 + a4 // middle


 M = 2^32-5   = 1 | 2 | 3 | 4     => 1 byte  = N & 63;  // (N <<24)>>24;

     a1 a2
*/



 unsigned M = (1<<24) + (2<<16) + (3<<8) + 4; // 01020304
 unsigned a1 = M & 0xFF;
 unsigned a2 = (M & 0xFF00)>>8;

 if( (a1 == 4) && (a2==3)) { printf("little"); }
 else if ((a1 == 4) && (a2==2)) {printf("middle");}
 else if (a1==1) { 
    printf("big");
 }  
 else{
   printf("unknown");
 }

 
