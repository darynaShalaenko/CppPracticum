#include <iostream>
#define N 256

double cheb(int n, double x){
    double t0=1, t1=x, tn=t1;
    for (int i=2;i<=n;i++){
        tn=2*x*t1-t0;
        t0=t1;
        t1=tn;
    }
    return tn;
}

int output(double mas[], int size){
    for (int i=0; i<size; ++i){
        printf("mas[%d]=%lf \n", i, mas[i]);
    }
    return 0;
}

double kf_cheb(int n){
    n++;
    double mas1[N];
    double mas2[N];
    double mas3[N];
    double masn[N];
    for (int i=0;i<=n;i++){
        mas1[i]=0;
        mas2[i]=0;
        mas3[i]=0;
        masn[i]=0;
    }
    mas1[0]=1;
    mas2[1]=1;
    for (int i=0;i<n-2;i++){
        for (int i=n;i>=1;i--){
            mas3[i]=2*mas2[i-1];
        }
        mas3[0]=0;
        for (int i=0;i<=n;i++){
            masn[i]=mas3[i]-mas1[i];
        }
        for (int i=0;i<=n;i++){
            mas1[i]=mas2[i];
        }
        for (int i=0;i<=n;i++){
            mas2[i]=masn[i];
        }
    }
    output(masn, n);
    return 0;
}


int main() {
    int n;
    double x;
    do{
        printf("N=");
        scanf("%d",&n);
    }while (n==0|| n>256);
    printf("x=");
    scanf("%lf",&x);
    printf("%lf \n",cheb(n,x));
    kf_cheb(n);
}
