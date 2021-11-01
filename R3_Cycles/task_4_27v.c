#include <stdio.h>
#include <math.h>

int main()
{
    float eps;
    scanf("%f",&eps);
    float k=1;
    float m=1;
    float sum=4;
    while(sum>=eps){
        k=k+1;
        m=m+1;
        sum=sum+(8*1/(pow(4*m-2,k)));
        printf("%f\n",sum);
    }

    printf("%f",sum);

}
