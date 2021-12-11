#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define N 100

void inputa(long* array, int n) {
    for (int i = 0; i<n; i++) {
        printf("array[%d] = ", i);
        scanf("%ld", &array[i]);
    }
}

void printa(long* array, int n){
    printf("\n");
    for (int i = 0; i<n; i++) {
        printf("%ld ", array[i]);
    }
}

void list_of_degrees(long* mas, int n, long* masl, long l){
    long max = mas[0], j=2;
    for (int i=1; i<n; i++){
        if (max < mas[i]){
            max = mas[i];
        }
    }
    while (l < max){
        l*=l;
        masl[j]=l;
        j+=1;
    }
}

int find_degrees(long* mas, int n, long* masl){
    int count = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (mas[i] == masl[j]){
                count += 1;
            }
        }
    }
    return count;
}

int find_deg(long* mas, int n, long n1){
    int count = 0, s;
    for (int i=0; i<n; i++){
        double s = log(mas[i]) / log(n1);
        if (fmod(s, 1) < DBL_EPSILON){
            count += 1;
        }
    }
    return count;
}

int main(){
    int n;
    long n1 = 2, n2 = 3;
    printf("n: ");
    scanf("%d", &n);
    long* array = (long*) malloc(sizeof(long)*n);
    inputa(array, n);
    printa(array, n);
    printf("\nDegrees of 2: %d", find_deg(array, n, n1));
    printf("\nDegrees of 3: %d", find_deg(array, n, n2));
}
