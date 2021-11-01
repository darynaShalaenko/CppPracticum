#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    if(n<=2){
        printf("error");
    }
    else{
        float p;
        float proisv=1;
        for (int i=1;i<=n;i++){
            p=(1+1/pow(i,2));
            proisv*=p;
        }printf("%f",proisv);


    }
}
