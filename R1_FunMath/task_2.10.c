#include <stdio.h>
#include <math.h>


float Myfuncangle(float x,float y,float z){
    float res=(acos((pow(z,2)-pow(x,2)-pow(y,2))/(-2*x*y)))*(180/3.14158f);
    return res;
}
int main()
{
    float a,b,c;
    printf("a=");
    scanf("%f",&a);
    printf("b=");
    scanf("%f",&b);
    printf("c=");
    scanf("%f",&c);
    printf("angle between a and b=");
    float angle1=Myfuncangle(a,b,c);
    printf("%.2f\n",angle1);
    printf("angle between a and c=");
    float angle2=Myfuncangle(a,c,b);
    printf("%.2f\n",angle2);
    printf("angle between b and c=");
    float angle3=Myfuncangle(b,c,a);
    printf("%.2f\n",angle3);
    float angle1radian=angle1/(180/3.14158f);
    printf("angle1radian=%.2f\n",angle1radian);
    float angle2radian=angle2/(180/3.14158f);
    printf("angle2radian=%.2f\n",angle2radian);
    float angle3radian=angle3/(180/3.14158f);
    printf("angle3radian=%.2f\n",angle3radian);





}
