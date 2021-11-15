#include<stdio.h>
#include <string.h>
#include <math.h>

#define P 3;


unsigned customHash(const char* str) {
    unsigned p = 1;
    
    unsigned res = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; ++i) {
        unsigned ch = (unsigned)str[i];
        p *= P;
        ch *= p;

        res += (res + ch) & ((1 << 32) - 1);
    }
    return res;
}

int main() {
    char str[100];
    fgets(stdin,str);
    printf("%u", customHash(str));
}
