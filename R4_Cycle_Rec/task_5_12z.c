#include <stdio.h>
#include <math.h>

int main()
{
    float eps;
    printf("eps=");
    scanf("%f",&eps);
    float x;
    printf("x=");
    scanf("%f",&x);
    float prev=0;
    float current=1;
    int k=1;
    while (fabs(current-prev)>=eps){
        prev=current;
        current+=(k+1)*pow(-x,k);
    }
    printf("%f",current);
}
