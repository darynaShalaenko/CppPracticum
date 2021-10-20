#include <stdio.h>
#include <math.h>


int main() {
    double y = 0, x, adding, eps, fact = 1;
    unsigned k = 0;
    printf("x = ");
    scanf("%lf", &x);
    do {
        printf("eps (eps > 0) = ");
        scanf("%lf", &eps);
    } while (eps <= 0);
    adding = x;
    while (adding >= eps) {
        y += adding;
        k++;
        fact *= (2*k) * (2*k+1);
        adding = pow(x, 2*k+1) / fact;
    }
    printf("y = %lf\nsinh(x) = %lf", y, sinh(x));
}
