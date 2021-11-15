#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double randDouble() {
    return fmod((double)rand() / (double)rand(),13.0); // srand(time(NULL))  isn't working
}


void printArray2(double* array, unsigned n){
    printf("\n");
    for (unsigned i = 0; i<n; i++) {
        printf("%lf ", array[i]);
    }
}


void printArray3(double** array, unsigned n, unsigned m) {
    printf("\n");
    for (unsigned i=0; i<n; i++) {
        printArray2(array[i], m);
    }
}


void fillArray(double* array, unsigned n) {
    for (unsigned i=0; i<n; i++) {
        array[i] = randDouble();
    }
}


void fillArray3(double** array, unsigned n, unsigned m) {
    for (int i=0; i<n; i++) {
        array[i] = malloc(sizeof(double)*m);
        fillArray(array[i], m);
    }
}


void freeArray(double** array, unsigned n){
    if (!array) return;
    for (unsigned i=0; i<n; i++) free (array[i]);
    free(array);
}


int findMaxElLineArray3(double** array, unsigned n, unsigned m) {
    double max_el=array[0][0];
    int line = 0;
    for (unsigned i=0; i<n; i++) {
        for (unsigned j=0; j<m; j++) {
            if (array[i][j]>max_el) {
                max_el = array[i][j];
                line = i;
            }
        }
    }
    return line;
}


void newLineAfterMaxElArray(double** array, unsigned n, unsigned m) {
    int max_line = findMaxElLineArray3(array, n, m);
    printf("\nMAX_EL_LINE = %d", max_line);
    max_line++;
    double **swap_array = (double**)malloc(sizeof(double*)*n);
    fillArray3(swap_array, n, m);
    for (unsigned i=0; i<n; i++) {
        for (unsigned j=0; j<m; j++) {
            swap_array[i][j] = array[i][j];
        }
    }
    freeArray(array, n);
    array = (double**)malloc(sizeof(double*)*(n+1));
    fillArray3(array, n+1, m);
    unsigned i1=0, j1=0;
    for (unsigned i=0; i<=n; i++) {
        if (i != max_line) {
            for (unsigned j=0; j<m; j++) {
                array[i][j] = swap_array[i1][j1++];
            }
            i1++;
            j1=0;
        } else {
            for (unsigned j=0; j<m; j++) {
                array[i][j] = randDouble();
            }
        }
    }
}


void newColArray(double** array, unsigned n, unsigned m, unsigned k) {
    for (unsigned i=0; i<n; i++) {
        double *swap_array = (double*)malloc(sizeof(double)*m);
        for (unsigned j=0; j<m; j++) {
            swap_array[j] = array[i][j];
        }
        free(array[i]);
        array[i] = malloc(sizeof(double)*(m+1));
        unsigned f=0;
        for (unsigned j=0; j<=m; j++) {
            if (j!=k) array[i][j] = swap_array[f++];
            else array[i][j] = randDouble();
        }
        free(swap_array);
    }
}


int main() {
    unsigned N, M;
    printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

    double **array = (double**)malloc(sizeof(double*)*N);
    fillArray3(array, N, M);
    printArray3(array, N, M);

    unsigned k;
    printf("\nk = ");
    scanf("%d", &k);
    newColArray(array, N, M, k);
    M++;
    printArray3(array, N, M);

    printf("\n\n\nNext part");
    //array[0][0] = 777777;
    printArray3(array, N, M);
    newLineAfterMaxElArray(array, N, M);
    N++;
    printArray3(array, N, M);

    freeArray(array, N);
}

