

#include <iostream>
#include <stdlib.h>
#define N 100

int** allocate_mat(int n, int m){
    int** a=(int**) calloc(n, sizeof(int*));
    for(int i=0;i<n;i++){
        a[i]=(int*) calloc(m, sizeof(int));
    }
    return a;
}

int** input_matrix(int* n, int* m){
    int n1,m1;
    printf("Розмірність матриці:n m");
    scanf("%d %d",&n1, &m1);
    *n=n1;
    *m=m1;
    int** a=(int**) calloc(n1, sizeof(int*));
    for(int i=0;i<n1;i++){
        a[i]=(int*) calloc(m1, sizeof(int));
    }
    for (int i=0; i<n1; i++){
        for (int j=0; j<m1; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}


int output_matrix(int** a, int n, int m){
    printf("\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d  ",a[i][j] );
        }
    printf("\n");
    }
    return 1;
}

void deallocate_matrix(int** a, int n, int m){
    for(int i=0;i<m;i++){
        free(a[i]);
    }
    free(a);
}

int mult_matrix(int** matr1,int n1,int m1,int** matr2,int n2,int m2,int** matr3){
    for (int i=0; i<n1; i++){
        for (int j=0; j<m2; j++){
            for (int k=0; k<n2; k++){
                matr3[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    return 0;

}

int main() {
    int** matr[N];
    int vect_nm[N];
    int n;
    printf("Кількість матриць: ");
    scanf("%d",&n);
    int q=0;
    for (int i=0; i<n; i++){
        int n1,m1;
        int** a=input_matrix(&n1, &m1);
        matr[i]=a;
        vect_nm[q]=n1;
        vect_nm[q+1]=m1;
        q=q+2;
    }

    int ** a1=matr[0];
    int ** a2=matr[1];
    int n1=vect_nm[0],m1=vect_nm[1],n2=vect_nm[2],m2=vect_nm[3], w=4;
    //int ** an= allocate_mat(n1, m1);

    for (int i=1; i<n; i++){
        if(m1==n2) {
            int nn=n1, mn=m2;
            int ** an= allocate_mat(nn, mn);
            mult_matrix(a1,n1,m1,a2,n2,m2,an);
            a1=an;  a2=matr[i];
            n1=nn;  m1=mn; n2=vect_nm[w];  m2=vect_nm[w+1];
            w=w+2;
        }
        else printf("Добуток всього масиву матриць неможлива");
    }
    output_matrix(a1, n1, m1);
    deallocate_matrix(a1, n1, m1);
    deallocate_matrix(a2, n2, m2);
    return 0;
}
