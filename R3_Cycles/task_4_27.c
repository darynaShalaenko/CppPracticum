#include <stdio.h>
#include <math.h>


int main() {
    double e, pi = 0, term, k = 2;
    printf("e = ");
    scanf("%lf", &e);
    term = 1;
    while (term >= e) {
        pi += term;
        term = 1/(k*k);
        k++;
    }
    pi = sqrt(pi*6);
    pi -= fmod(pi, e); //??? needed because of adding divisioned double
    printf("Pi = %lf", pi);
}
