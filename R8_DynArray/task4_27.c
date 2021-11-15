#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int n,a,b;
    printf("n=");
    scanf("%d",&n);
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    int max_sum=0;
    int max_k=0;
    int max_m=0;
    for(unsigned int k=1;k<=n;k++){
        for(unsigned int m=1;m<=n;m++){
            if(k*a+m*b==n){
                printf("%d and %d\n",k,m);
                int res=fabs(k)+fabs(m);

                if(res>=max_sum){
                    max_sum=res;
                    max_k=k;
                    max_m=m;
                }


            }

        }
    }
    if(max_sum==0){
        printf("a*k+b*m!=n");
    }
    else{
        printf("%d",max_sum);
        printf("\n");
        printf("max_k=%d",max_k);
        printf("\n");
        printf("max_m=%d",max_m);
    }






}
