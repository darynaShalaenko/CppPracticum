
#include <stdio.h>


typedef struct {
    int n, m;
    double values[255][255];
} Matrix;


Matrix inputMatrix() {
    Matrix matr;
    printf("n = ");
    scanf("%d", &matr.n);
    printf("m = ");
    scanf("%d", &matr.m);
    for (int i=0; i<matr.n; i++) {
        for (int j=0; j<matr.m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &matr.values[i][j]);
        }
    }
    return matr;
}


void printMatrix(Matrix matr) {
    for (int i=0; i<matr.n; i++) {
        printf("\n");
        for (int j=0; j<matr.m; j++) {
            printf("%g ",matr.values[i][j]);
        }
    }
}


int main() {
    Matrix M1;
    M1 = inputMatrix();
    printMatrix(M1);
}
