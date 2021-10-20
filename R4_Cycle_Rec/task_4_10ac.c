#include <stdio.h>
#include <math.h>


int main() {
    int sum, a0, a1 = 1, a2 = 0;
    unsigned n;
    sum = 2*a2 + 4*a1;
    printf("n = ");
    scanf("%d", &n);
    for (unsigned k = 3; k <= n; k++) {
        a0 = a1 + k*a2;
        sum += pow(2, k)*a0;
        a2 = a1;
        a1 = a0;
    }
    printf("S(%d) = %d", n, sum);
}
