#include <stdio.h>


int main() {
    int n, swapper, a1, a2, a3, counter = 0;
    printf("n = ");
    scanf("%d", &n);
    printf("Enter number: ");
    scanf("%d", &a3);
    printf("Enter number: ");
    scanf("%d", &a2);
    if (a3 > a2) counter++; // needed if only one neighbor counts
    for (int i = 2; i<n; i++) {
        printf("Enter number: ");
        scanf("%d", &a1);
        if (a2 > a1 && a2 > a3) {
            counter++;
            printf("\n %d %d %d. C= %d", a3, a2, a1, counter);
        }
        a3 = a2;
        swapper = a1; // needed if only one neighbor counts
        a2 = a1;
    }
    if (swapper > a3) counter ++; // needed if only one neighbor counts
    printf("There are %d numbers, that are greater then their neighbors", counter);
}
