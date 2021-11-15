#include <iostream>
using namespace std;
#define N 100

void write_binary_file(char* filename, int arr[], int n) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    fwrite(arr, sizeof (float), n, f);

    fclose(f);
}

int read_binary_file(char* filename, int arr[]) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int n = size / sizeof (float);

    fseek(f, 0, SEEK_SET);
    fread(arr, sizeof (float), n, f);

    fclose(f);
    return n;
}

int sanya(int arr[], int n)
{
    int max = -1;
    int len = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            len += 1;
        }
        else
        {
            max = len;
            len = 1;
        }
    }
    return max > len ? max : len;
}

int main() {
    char F[10] = "F.int";
    char G[10] = "G.int";


    int n1 = 8;
    int arr1[N] = {1, 2, 3, 2, 5, 6, 7, 8};    


    write_binary_file(F, arr1, n1);

    int arr2[N] = {};
    int n2 = read_binary_file(F, arr2);
    for(int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << sanya(arr2, n2) << endl;




    return 0;
}

