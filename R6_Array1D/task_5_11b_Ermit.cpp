#include <stdio.h>
#include<math.h>
//#define N 256

double Ermit(int n, double x, double *hn){

    double h0=1, h1=2*x;

    for (int i=2;i<=n;i++){

        hn[i]=2*x*h1-2*(i-1)*h0;
        h0=h1;
        h1=hn[i];
    }
    return h1;
}



int main() {
    int n;
    double x, hn[256];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter x: ");
    scanf("%lf",&x);
    printf("Result: %lf \n",Ermit(n,x,hn));
}
