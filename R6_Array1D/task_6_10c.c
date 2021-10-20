#include <stdio.h>
#include <math.h>
#define N 100


void ShowArray(int array[], unsigned n) {
    for (unsigned i=0; i<n; i++) {
         printf("%d ", array[i]);
    }
}


void InputArray(int mas[], unsigned n) {
    for (unsigned i=0; i<n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &mas[i]);
    }
}


int CountCompleteSquares(int array[], unsigned n) {
    int counter = 0;
    for (unsigned i=0; i <= n/2; i++) {
        if (fmod(sqrt(array[i]*array[n-i-1]), 1) < 0.000001) {
            counter++;
            printf("\n%d*%d = %d = %g^2", array[i], array[n-i-1], array[i]*array[n-i-1], sqrt(array[i]*array[n-i-1]));
        }
    }
    return counter;
}


int main() {
    int array[N];
    unsigned n;
    printf("n = ");
    scanf("%d", &n);
    InputArray(array, n);
    ShowArray(array, n);
    printf("\nThere are %d complete squares!", CountCompleteSquares(array,n));
}
