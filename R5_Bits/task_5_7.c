#include <stdio.h>

int main(){
    unsigned M = (1<<24) + (2<<16) + (3<<8) + 4;
    unsigned a1 = M & 0xFF;
    unsigned a2 = (M & 0xFF00)>>8;

    if ((a1==4) && (a2==3)) {
        printf("little endian");

    }
    else if ((a1==4) && (a2==2)) {
        printf("middle endian");

    }
    else if ((a1==1)) {
        printf("big endian");

    }
    else{
        printf("Unknown");

    }
}
