
#include <iostream>
unsigned max(unsigned n, unsigned m){
    if(n>m) return n;
    else return m;
}

int zeron(unsigned n, unsigned m){
    unsigned s=0;
    for(unsigned i=1;s<max(n,m);i<<=1){
        s=s+i;
    }
    if ((m|n)==s){
        return 1;
    }
    else return 0;
}

int main() {
    unsigned n, m;
    printf("n=\n");
    scanf("%u", &n);
    printf("m=\n");
    scanf("%u", &m);
    if (zeron(n,m)) printf("true");
    else printf("false");
}
