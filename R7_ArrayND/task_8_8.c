#include <stdio.h>
#include <math.h>

#define N 100
#define M 100


void printArray(double array[N][M], unsigned n, unsigned m) {
    printf("\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%g ", array[i][j]);
        }
        printf("\n");
    }
}


void inputArray(double array[N][M], unsigned n, unsigned m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &array[i][j]);
    }
    }
}


void rotateArray(double array[N][M], unsigned n, unsigned m) {
    double swapper[N];
    for (unsigned i=0; i<n; i++) {
        for (unsigned j=0; j<m; j++) {
            swapper[j] = array[j][i];
        }
        for (unsigned j=0; j<m; j++) {
            array[j][i] = swapper[m-j-1];
        }
    }
}


int main() {
    unsigned n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);


    double array[N][M];
    inputArray(array, n, m);
    printArray(array, n, m);
    rotateArray(array, n, m);
    printArray(array, n, m);
}
