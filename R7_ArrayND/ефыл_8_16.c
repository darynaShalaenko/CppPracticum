
#include <iostream>
#define N 101

void vyvod(int matr[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d, ",matr[i][j]);
        }
        printf("\n");
    }
}


void vvod(int matr[N][N], int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("\na[%u][%u]=",i,j);
            scanf("%d", &matr[i][j]);
        }
    }
}

void dzer(int matr[N][N],int n){
    for(int i=0; i<n; i++){
        for(int j=0; i+j<n-1; j++){
            int t=matr[i][j];
            matr[i][j]=matr[n-1-j][n-1-i];
            matr[n-1-j][n-1-i]=t;
        }
    }
}

int main() {
    int n;
    do{
        printf("Порядок матриці:");
        scanf("%d",&n);
      } while(n%2==0);
    int matr[N][N];
    vvod(matr,n);
    vyvod(matr,n);
    dzer(matr,n);
    printf("\n");
    vyvod(matr,n);
}


