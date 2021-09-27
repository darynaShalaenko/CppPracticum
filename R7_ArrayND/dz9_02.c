#include <stdio.h>

float maximum(int n,float* arr){
    double m = arr[0];
    for (int j = 0; j <= n; j++){
        if ( m < arr[j]){
            m = arr[j];
        }
    }
    return m;
}
float minimum(int n,float* arr){
    double m = arr[0];
    for (int j = 0; j <= n; j++){
        if ( m > arr[j]){
            m = arr[j];
        }
    }
    return m;
}
int main(){
    int n,m;
    printf("n = ");
    scanf("%d",&n);
    printf("m = ");
    scanf("%d",&m);
    float minn[n], maxx[n];
    float matr[n][m],matr2[n][m];
    for (int i = 0; i < n; i++){
        float mas[m];
        for (int j = 0; j < m; j++){
            printf("matrix(%d,%d) = ",i,j);
            scanf("%f",&matr[i][j]);
            matr2[i][j] = matr[i][j];
            mas[j] = matr[i][j];
        }
        minn[i] = minimum(m,mas);
        maxx[i] = maximum(m,mas);
    }
    float mymin = minimum(n,minn), mymax = maximum(n,maxx);
    int mni = 0, mxi = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matr[i][j] == mymin){
                mni = i;
            }
            else if (matr[i][j] == mymax){
                mxi = i;
            }
            if (mni != mxi){
                for (int j = 0; j < m; j++){
                matr2[mni][j] = matr[mxi][j];
                matr2[mxi][j] = matr[mni][j];
                }
            }
        }
    }
    printf("my matrix: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%f  ",matr2[i][j]);
    }
    printf("\n");
    }
}

