include <stdio.h>


int main() {
    unsigned n;
    printf("n = ");
    scanf("%d", &n);
    double a1 = 1, a2 = 0, b1 = 0, b2 = 1, b0, a0, sum = 0;
    sum += 2.0 / (a2+b2) + 2.0/(a1+b1);
    for (int k = 3; k <=n; k++) {
        b0 = b1 + a1;
        a0 = a1/k + a2*b0;
        sum += 2.0 / (a0+b0);
        a2 = a1;
        a1 = a0;
        b2 = b1;
        b1 = b0;
    }
    printf("S(n) = %lf", sum);
}
