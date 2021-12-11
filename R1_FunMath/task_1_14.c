#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float a,S,t1,t2 ,v;
    scanf("%f/n" , &a);
    scanf("%f/n", &t1);
    scanf("%f/n", &v);
    S=a*t1*t1/2;
    t2=v/a;
    printf("The distance it will travel in time from the beginning of the movement - ");
    printf("%f\n", S);
    printf("The time it takes for the object to reach speed kilometers per hour - ");
    printf("%f\n", t2);




    return 0;
} 
