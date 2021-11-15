#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double arr[],int size)
{
    double sum;
    for(int i = 0;i<size;i++)
    {
        double x1 = 100*arr[i+1] - arr[i];
        double x2 = arr[i] - 1;
        sum += pow(x1,2) + pow(x2,2);
    }
    return sum;
}

int main(){
    unsigned n = 5;
    double arr[n] = {0,0,0,0,0};
    double res = func(arr,n);
    printf("%lf",res);
}
