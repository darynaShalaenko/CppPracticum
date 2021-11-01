#include <stdio.h>
#include <math.h>



int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    if(n==1){
        printf("sum=1/2");
    }
    else if(n==2){
        printf("sum=1/4");
    }
    else{
        float a1=1;
        float a2=1;
        float a3=1;
        float a4;
        float sum=0.875;
        for (int k=4;k<=n;k++){
            a4=a1+a3;
            a1=a2;
            a2=a3;
            a3=a4;
            sum+=a4/pow(2,k);

        }
    printf("%f",sum);

    }
}
