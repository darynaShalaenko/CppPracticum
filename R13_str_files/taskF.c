#include <cstdlib>
#include <cstdio>
#define F "F.int64"
#define N 100


void input_until_zero_to_file(char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    int n = 0;
    int arr[N];
    while (true) {
        scanf("%ld", &arr[n]);
        if (arr[n] == 0)

            break;
        n++;
    }
    fwrite(arr, sizeof (int), n, f);

    fclose(f);
}



void print_int_from_file(char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    unsigned long long k = size / sizeof (int);

    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < k; i++) {
        int num;
        fread(&num, sizeof (int), 1, f);
        printf("%ld ", num);
    }
    printf("\n");

    fclose(f);
}


int sum_of_elements_in_file(char* filename) {
    FILE *f = fopen(filename, "rb");
    int sum;
    if (!f) exit(1);
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    unsigned long long k = size / sizeof(int);
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < k; i++) {
        int num;
        sum +=num;

    }
    printf("%ld ", sum);
    fclose(f);
}


int main() {
    printf("Enter elements of the array (if you want to stop the program enter 0):");
    input_until_zero_to_file(F);
    printf("Entered array :");
    print_int_from_file(F);
    printf("Sum of elements in the array :");
    sum_of_elements_in_file(F);
    return 0;
} 
