#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef unsigned long long LONG;

int main()
{
    unsigned n = 32;
    LONG* arr = (LONG*)malloc(sizeof(LONG) * n);

    const char* filename = "input.txt";
    ifstream fin;
    fin.open(filename);

    LONG tmp;
    unsigned k=0;
    for ( ; fin >> tmp; k++)
    {
        if (k == n)
        {
            n <<= 2;
            arr = (LONG*)realloc(arr, sizeof(LONG) * n);
        }
        arr[k] = tmp;
    }

    for (int i=k-1; i > -1; i--)
    {
        cout.precision(3);
        cout.setf(std::ios::fixed);
        cout << sqrt(arr[i]) << endl;
    }

    return 0;
}
