
    ShowArray(array, n, m);
}
54 8_6.c
Viewed
@@ -0,0 +1,54 @@
#include <stdio.h>

#define N 100
#define M 100


void ShowArray(double array[N][M], unsigned n, unsigned m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%g ", array[i][j]);
        }
        printf("\n");
    }
}


void InputArray(double array[N][M], unsigned n, unsigned m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &array[i][j]);
    }
    }
}


double MaxCol(double array[N][M], unsigned n, unsigned m, int k) {
    double res;
    for (unsigned i = 0; i<n; i++) {
        for (unsigned j = 0; j<m; j++) {
            if (i-j == k) res += array[i][j];
    }}
    return res;
}


int main() {
    int k;
    double array[N][M];
    unsigned n = 101, m = 100;
    while (n > 20) {
        printf("n = ");
        scanf("%d", &n);
    }
    while (m > 20) {
        printf("m = ");
        scanf("%d", &m);
    }
    printf("k = ");
    scanf("%d", &k);
    InputArray(array, n, m);
    ShowArray(array, n, m);
    printf("%lf", MaxCol(array, n, m, k));
}
