
#include <stdio.h>
#include <stdlib.h>

double A, B, C, arifm, geom;

int main() {

    printf ("A=");
    scanf("%lf,", &A);
    printf ("B=");
    scanf("%Elf", &B);
    printf ("C=");
    scanf("%lf", &C);
    arifm=(A+B+C)/3;
    geom=3 / (1 / A + 1 / B + 1 / C);
    printf(" floating point format: %lf %lf ",arifm, geom); 
    printf(" scientific format: %le %le ",arifm, geom); 
}


