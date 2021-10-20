#include <iostream>

unsigned ferlas(unsigned n){
    unsigned i=1, k=0;
    for(;i<=n<<1;i<<=1){
        if((i&n)==0){
            n=n|(1<<k);
            break;
        }
        k++;

    }
    unsigned j=1<<sizeof(n)*8, q=1, n1=0;
    for(;q<sizeof(n)*8;j>>=1){
        if (n1<<1==n>>(sizeof(n)*8-q)){
            n=n|(1<<(sizeof(n)*8-q));
            break;
        }
        n1=n>>(sizeof(n)*8-q);
        q++;
    }
    return n;
}

int main() {
    unsigned n;
    printf("n=\n");
    scanf("%u", &n);
    printf("%u\n",ferlas(n));
}
