#include <iostream>
#include <stdio.h>

using namespace std;

void inp_arr(double* arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("arr[%i] = ", i);
        cin >> arr[i];
    }
}

void print_arr(double* arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("arr[%d] = %f\n", i, arr[i]);
    }
}

void write_file(char* filename, double* arr, int n)
{
    FILE* f = fopen(filename, "wb");
    fwrite(arr, sizeof(*arr), n, f);
    fclose(f);
}

int read_file(char* filename, double* arr)
{
    FILE* f = fopen(filename, "rb");
    int i = 0;
    while (!feof(f))
    {
        if (fread(&arr[i], sizeof(*arr), 1, f) != 1) break;
        i++;
    }
    fclose(f);
    return i;
}

void func1(char* fin_name, char* fout_name, double a)
{
    FILE* fin = fopen(fin_name, "rb");
    FILE* fout = fopen(fout_name, "wb");

    double tmp;
    while (!feof(fin))
    {
        fread(&tmp, sizeof(tmp), 1, fin);
        if (abs(tmp) < a) fwrite(&tmp, sizeof(tmp), 1, fout);
    }
    fclose(fin);
    fclose(fout);
}

//void func2(char* filename, int n)
//{
//
//}

int main()
{
    int n;
    cin >> n;
    double a;
    cin >> a;
    double arr[n];
    inp_arr(arr, n);
    char* fin="f", *fout="g";
    write_file(fin, arr, n);
//    double arr2[n];
//    int k = read_file(fin, arr2);
//    print_arr(arr2,k);
    func1(fin, fout, a);
    double arr2[n];
    int k = read_file(fout, arr2);
    print_arr(arr2, k);
}
