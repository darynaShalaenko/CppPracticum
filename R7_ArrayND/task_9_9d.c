

#include <iostream>
#include <iostream>
#include <stdlib.h>

double** allocate_mat(int n, int m){
    double** a=(double**) calloc(n, sizeof(double*));
    for(int i=0;i<n;i++){
        a[i]=(double*) calloc(m, sizeof(double));
    }
    return a;
}

int input_matrix(double** a, int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    return 1;
}

int output_matrix(double** a, int n, int m){
    printf("\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%lf  ",a[i][j] );
        }
    printf("\n");
    }
    return 1;
}

int klstovb(double** a, int n, int m){
    int res=0;
    for (int j=0; j<m; j++){
        int k=0;
        for (int i=0; i<n; i++){
            if (a[i][j]>1) break;
            k++;
        }
        if (k==n) res++;
    }
    return res;
}


int delstmen_1(double** a, int n, int m, double** a1, int m1){
    int q=0;
    for (int j=0; j<m; j++){
        int k=0;
        for (int i=0; i<n; i++){
            if (a[i][j]<1){
            k++;
            }
        }
        if (k!=n){
            for (int r=0; r<n; r++){
                a1[r][q]=a[r][j];
            }
            q++;
        }
    }
    return 0;

}

void deallocate_matrix(double** a, int n, int m){
    for(int i=0;i<m;i++){
        free(a[i]);
    }
    free(a);
}

int main() {
    int n, m;
    printf("N=");
    scanf("%d",&n);
    printf("M=");
    scanf("%d",&m);
    double ** a= allocate_mat(n, m);
    input_matrix(a, n, m);
    int m1=m-klstovb(a,n,m);
    double ** a1= allocate_mat(n, m1);
    delstmen_1(a, n, m, a1, m1);
    output_matrix(a1,n , m1);
    deallocate_matrix(a, n, m);
    deallocate_matrix(a1, n, m1);
    return 0;
}
