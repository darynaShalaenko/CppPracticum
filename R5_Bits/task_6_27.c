#include <stdio.h>

void func(int n1, int n2){
    int res = n1 ^ n2;
    if (res == 255){
        printf("true");
    }
    else{
        printf("false");
    }
}

int main(){
    int n1, n2;
    do{
        printf("n1=");
        scanf("%d",&n1);
    } while (n1<=0);
    do{
        printf("n2=");
        scanf("%d",&n2);
    } while (n2<=0);
    func(n1,n2);
} 
