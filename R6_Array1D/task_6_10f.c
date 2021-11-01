#include <stdio.h>
#include <math.h>

int func_f(int mas[], int size){
    int c=0;
    for(int i=0; i<size; i++){
        unsigned m = sqrt(mas[i]);
        if(m%2!=0){
            c+=1;
        }
    }
    return c;
}

int main(){
    int mas[100], n, c;
    do{
        printf("n=");
        scanf("%d",&n);
    }while(n<1);
    for(int i=0; i<n; i++){
        printf("mas[%d]=",i);
        scanf("%d",mas[i]);
    }
    c=func_f(mas,n);
    printf("Count=%d",c);
}
