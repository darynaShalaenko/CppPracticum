#include <stdio.h>
#include <math.h>
#define N 8


int main(){
    int a[N]={2,5,10,57,8,15,32,21}, max, min, av, res, res0;
    max=a[0];
    min=a[0];
    for(int i=1; i<N; i++){
        if(a[i]>max){
            max=a[i];
        }
        else if(a[i]<min){
            min=a[i];
        }
    }
    av=(max+min)/2;
    printf("max=%d, min=%d, average=%d", max, min, av);

    res=abs(av-a[0]);
    res0=a[0];
    for(int i=1; i<N; i++){
        if(abs(av-a[i])<res){
            res=abs(av-a[i]);
            res0=a[i];
        }
    }
    printf("\nres=%d",res0);
}
