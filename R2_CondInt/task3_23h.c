#include <stdio.h>
#include <math.h>

float sinc(float x)
{
    float answer;
    float eps = 0.000001;
    if (fabs(x) < eps){
        answer = 1;
    }
    else{
        answer = sin(x)/x;
    }
    return answer;
}

float sinc_derivative(float x)
{
    float answer;
    float eps = 0.000001;
    if (fabs(x) < eps){
        answer = 0;
    }
    else{
        answer = (cos(x)*x - sin(x))/(x*x);
    }
    return answer;
}

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);
    printf("sinc(x) = %f\n", sinc(x));
    printf("sinc_derivative(x) = %f\n", sinc_derivative(x));
}
