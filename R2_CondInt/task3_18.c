#include <iostream>
#include <stdio.h>
float max(float a, float b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}
float min(float a, float b){
    if (a<b){
        return a;
    }
    else{
        return b;
    }
}
int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4;
    printf("кординати лівого нижнього кута першого прямокутника\n");
    scanf("%f %f", &x1,&y1);
    printf("\nкординати правого верхнього кута першого прямокутника\n");
    scanf("%f %f", &x2,&y2);
    printf("кординати лівого нижнього кута другого прямокутника\n");
    scanf("%f %f", &x3,&y3);
    printf("кординати правого верхнього кута другого прямокутника\n");
    scanf("%f %f", &x4,&y4);

    printf("кординати лівого нижнього кута мінімального прямокутника:\n");
    printf(" %lf  %lf\n",min(x1,x3),min(y1,y3));
    printf("кординати правого верхнього кута мінімального прямокутника:\n");
    printf(" %lf  %lf\n",max(x2,x4),max(y2,y4));
}


