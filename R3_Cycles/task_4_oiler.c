
#include <iostream>

int oiler(int n){
    int s = n;
    for (int i=2; i*i<=n; i++)
        if (n%i==0){
            while (n%i==0)
                n=n/i;
            s=s-s/i;
        }
    if (n > 1)
        s=s-s/n;
    return s;
}

int main() {
    printf("%d\n",oiler(16));
}
