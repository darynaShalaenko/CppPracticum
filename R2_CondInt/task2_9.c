#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>  
using namespace std; 

int main()
{
    double x, y, z, a, b, c;
    printf("Enter x, y, z ");
    scanf("%lf %lf %lf",&x,&y,&z);
    a = x + y + z;
    b = x * y - x * z + y * z;
    c = x * y * z;

    if (a > b && a > c)
    {
        printf("Max = %lf",a);
    }else
    {
        if (b > a && b > c)
        {
            printf("Max = %lf",b);
        }else
        {
            printf("Max = %lf",c);
        }
    }

    if (a < b && a < c)
    {
        printf("\nMin = %lf",a);
    }else
    {
        if (b < a && b < c)
        {
            printf("\nMax = %lf",b);
        }else
        {
            printf("\nMax = %lf",c);
        }
    }



}
