#include <stdio.h>
#include <math.h>
#include <float.h>


int is_prime(unsigned n) {
    int m = ceil(sqrt(n+0.5));
    if (n == 1) return 0;
    for (int i=2; i<=m; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


void fileInput(const char* fname) {
    FILE* file = fopen(fname, "wb+");
    int item = 1;
    while(item != 0) {
        printf("Enter natural number(0 to exit): ");
        scanf("%d", &item);
        if (item == 0) break;
        int res = fwrite(&item, sizeof(int), 1, file);
//        printf("\nres = %d, item = %d", res, item);
        if (res < 1) printf("\nERROR while writing to file (in fileInput function), res = %d\n", res);
    }
    fclose(file);
}


void filePrint(const char* fname) {
    FILE* file = fopen(fname, "rb");
    printf("\nFile:\n");
    while (!feof(file)) {
        int item;
        int res = fread(&item, sizeof(int), 1, file);
        if (res < 1) {
            break;
        }
        printf("%d ", item);
    }
    fclose(file);
    printf("\n");
}


int countPrimesIfFile(const char* fname) {
    FILE* file = fopen(fname, "rb");
    printf("\nFile:\n");
    int counter = 0;
    while (!feof(file)) {
        int item;
        int res = fread(&item, sizeof(int), 1, file);
        if (res < 1) {
            break;
        }
        if (is_prime(item) == 1) counter ++;
    }
    fclose(file);
    return counter;
}


int main() {
    fileInput("11_6_d");
    filePrint("11_6_d");
    printf("Prime count: %d", countPrimesIfFile("11_6_d"));
}
