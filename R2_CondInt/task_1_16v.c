#include <stdio.h>
#include <math.h>

float xper(float l1,float l2,float l3){
    float x=(-l3+l2*l3)/(1-l1*l2);
    return x;
}
float rast(float v1,float v2,float w1,float w2){
    float res=sqrt(pow(v1-w1,2)+pow(v2-w2,2));
    return res;
}
int main()
{
    float x0,y0,a,b,c;
    printf("x0=");
    scanf("%f",&x0);
    printf("y0=\n");
    scanf("%f",&y0);
    printf("a=\n");
    scanf("%f",&a);
    printf("b=\n");
    scanf("%f",&b);
    printf("c=\n");
    scanf("%f",&c);
    printf("point1=");
    printf("%f",x0);
    printf(";%f\n",y0);
    printf("firstp=");
    printf("x");
    printf("+");
    printf("%2.f",b);
    printf("y+");
    printf("%2.f\n",c);
    printf("secondp=");
    printf("%2.f",a);
    printf("x");
    printf("+y+");
    printf("%2.f\n",c);


    float x1=xper(a,b,c);
    float y1=-c-a*x1;
    printf("pointofperecechenia=%f %f\n",x1,y1);
    float result=rast(x0,y0,x1,y1);
    printf("distance between points=%f",result);
}
