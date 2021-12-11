include <iostream>
#include <math.h>
#include <fstream>

#define size 128

using namespace std;

int main()
{
    ifstream F;
    int n = 0;
    int *arr = new int[size * 1024 / sizeof(int)];
    F.open("input.txt", ios::in);
    while (!F.eof()) {
        F >> arr[n++];
    }
    F.close();
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    cout << endl;
    for(int i = n; i > 0; i -- ){
        cout << sqrt((long double)arr[i - 1]) << endl;
    }
    delete[] arr;

    return 0;
}
