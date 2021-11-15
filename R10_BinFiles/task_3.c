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

bool sanya(int n)
{
    while(n % 3 == 0)
    {
        n /= 3;
        if(n == 1)
            return true;
    }
    return false;
}

int main() {
    char F[10] = "F.int";
    char G[10] = "G.int";


    int n1 = 0;
    int arr1[N] = {};


    printf("Enter the el of mas - > ");
    for(int i = 0; 1 ; i++)
    {
        cin >> arr1[i];
        n1 += 1;
        if(arr1[i] == 0)
            break;
    }
    n1 -= 1;

    write_binary_file(F, arr1, n1);

    int arr2[N] = {};
    int n2 = read_binary_file(F, arr2);
    for(int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int arr3[N] = {};
    int n3 = 0;

    for(int i = 0; i < n2; i++)
    {
        if(sanya(arr2[i]) == 1)
            arr3[n3++] = arr2[i]; 
    }

    write_binary_file(G, arr3, n2);
    for(int i = 0; i < n3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
