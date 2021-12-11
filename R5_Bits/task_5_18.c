#include <iostream>
using namespace std;
int main() {
    unsigned char n;

    scanf("%hhd", &n );
    int q=n;
    n=n<<1;
    q = q << 1 ;
    if (q>255)n=n+1;

    printf("%d\n", int(n));

} 
