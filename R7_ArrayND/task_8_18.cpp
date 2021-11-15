#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int** inp_matr(unsigned n, unsigned m)
{
    int** matr = (int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++)
    {
        matr[i] = (int*)malloc(sizeof(int) * m);
        for (int j=0; j<m; j++)
        {
            printf("matr[%d][%d] = ",i,j);
            cin >> matr[i][j];
        }
    }
    return matr;
}

void delete_matr(int** matr, unsigned n)
{
    for (int i=0; i<n; i++) free(matr[i]);
    free(matr);
}

void print_matr(int** matr, unsigned n, unsigned m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout.fill(' ');
            cout.width(6);
            cout << matr[i][j];
        }
        cout << endl;
    }
}

bool all_negative(int* arr, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i] >= 0) return 0;
    }

    return 1;
}

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_arr(int* arr1, int* arr2, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        swap(arr1+i, arr2+i);
    }
}

void func(int** matr, unsigned n, unsigned m)
{
    int *first, *last;
    first = nullptr;
    last = nullptr;
    bool flag = 0;
    for (int i=0; i<n; i++)
    {
        if (all_negative(matr[i], m))
        {
            cout<<"hello";
            if (!flag)
            {
                first = matr[i];
                flag = 1;
            }
            last = matr[i];
        }
    }
    if (last != first) swap_arr(first, last, m);
}

int main()
{
    unsigned n,m;
    cin >> n >> m;

    int** matr = inp_matr(n, m);

    print_matr(matr, n, m);

    func(matr, n, m);
    cout.width(20);
    cout.fill('=');
    cout << "" << endl;

    print_matr(matr, n, m);

    delete_matr(matr, n);
}
