#include <stdio.h>

int main()
{
    unsigned m = 134, nm;
    int k = 3, i = 0;
    while(i < k){
        nm = m & (~((1<<64 - i)));
        i += 1;
    }
    printf("m = %hhd\n", nm);
    i = 1;
    while(i <= k){
        m = m & (~((1<<i)));
        i += 1;
    }
    printf("m = %o\n", m);
    printf("m = %hhd\n", m);
    printf("for long long unsigned: \n");
    long long unsigned m2 = m;
    i = 0;
    while(i < k){
        nm = m & (~((1<<64 - i)));
        i += 1;
    }
    printf("m = %hhd\n", nm);
    i = 1;
    while(i <= k){
        m = m & (~((1<<i)));
        i += 1;
    }
    printf("m = %o\n", m);
    printf("m = %hhd\n", m);
} 
