#include <stdio.h>

int main(){
    int n,m,k;
    printf("n = ");
    scanf("%d",&n);
    printf("m = ");
    scanf("%d",&m);
    float matr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("matrix(%d,%d) = ",i,j);
            scanf("%f",&matr[i][j]);
        }
    }
    float matr2[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matr2[i][j] = matr[n - i-1][j];
            printf("%f\n  ",matr[i][j]);
            }
        }
    printf("your matrix: ");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%f  ",matr[i][j]);
    }
    printf("\n");
    }
    printf("my matrix: ");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%f  ",matr2[i][j]);
    }
    printf("\n");
    }
}

