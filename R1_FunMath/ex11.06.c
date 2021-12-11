//11.06г
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define F "F.int32"
#define N 100

void input_until_zero_to_file(char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    int n = 0;
    int arr[N];
    while (1) {
        scanf("%d", &arr[n]);
        if (arr[n] == 0)
            break;
        n++;
    }
    fwrite(arr, sizeof (int), n, f);

    fclose(f);
}

void print_from_file(char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int k = size / sizeof (int);

    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < k; i++) {
        int num;
        fread(&num, sizeof (int), 1, f);
        printf("%d ", num);
    }
    printf("\n");

    fclose(f);
}

void num_of_prime_numbers(char* filename_inp) {
    FILE* inp = fopen(filename_inp, "rb");
    if (!inp) exit(1);

    int num;
    int res=0;
    while (fread(&num, sizeof (int), 1, inp)) {
        int p=2;
        int dev=1;
        while(p<=floor(sqrt(num))){
            if (num%p==0) {
               dev=0;
               break;
            }
            p++;
        }
        if (dev==1)
           res+=1;
    }
    printf("%d ", res);
    fclose(inp);
}

int main() {
    input_until_zero_to_file(F);
    print_from_file(F);
    num_of_prime_numbers(F);
    return 0;
}