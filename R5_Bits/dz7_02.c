#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned m;
    unsigned n;
    printf("input m: \nm = ");
    scanf("%u", &m);
    printf("input n: \nn = ");
    scanf("%u", &n);
    for (int i = 0; i <= n; i++){
        m = m & ~(1 << i);
    }
    printf("m = %o\n", m);
    for (int j = 0; j <= n; j++){
        m = m & ~(1 << sizeof(m) - j);
    }
    printf("m = %o, %x", m,m);

}

