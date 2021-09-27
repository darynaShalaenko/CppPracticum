#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long m;
    unsigned n;
    printf("input m: \nm = ");
    scanf("%Lu", &m);
    printf("input n: \nn = ");
    scanf("%u", &n);
    for (int i = 0; i <= n; i++){
        m = m & ~(1 << i);
    }
    printf("m = %Lo\n", m);
    for (int j = 0; j <= n; j++){
        m = m & ~(1 << sizeof(m) - j);
    }
    printf("m = %Lo, %Lx", m,m);

}

