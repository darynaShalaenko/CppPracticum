#include <stdio.h>
#include <math.h>

float bent(float x)
{
    return (pow(x * x + 1, 0.5) - 1)/2 + x;
}
float bent_derivative(float x)
{
    return x/(2*pow(x * x + 1, 0.5)) + 1;
}
int main()
{
    float x;
    printf("Enter x\n");
    scanf("%f", &x);
    printf("bent(x) = %f\n", bent(x));
    printf("bent_derivative(x) = %f\n", bent_derivative(x));
}
