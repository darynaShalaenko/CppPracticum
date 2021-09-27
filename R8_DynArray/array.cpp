#include <stdio.h>
#include <stdlib.h>

int *my_alloc(int size) {
    return malloc(sizeof(int) * size);
}

void input(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Enter %i element: ", i);
        scanf("%i", &arr[i]);
    }
}

void print(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%i element: %i\n", i, arr[i]);
    }
}

int main() {
    int size = 0;

    printf("Enter array size: ");
    scanf("%i", &size);

    int *array = my_alloc(size);
    input(array, size);
    print(array, size);
}
