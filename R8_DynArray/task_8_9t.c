#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int** form_matr(unsigned n, unsigned m)
{
    int** matr = (int**) malloc(sizeof(int*) * n);
    srand(time(NULL));
    for (int i=0; i<n; i++)
    {
        matr[i] = (int*) malloc(sizeof(int) * m);
        for (int j=0; j<m; j++)
        {

            matr[i][j] = rand();
        }
    }

    return matr;
}

void delete_matr(int** matr, unsigned n)
{
    for (int i=0; i<n; i++) free(matr[i]);
    free(matr);
}

int* form_line(unsigned n)
{
    int* res = (int*)malloc(sizeof(int) * n);
    srand(time(NULL)+20000);
    for (int i=0; i<n; i++)
    {
        res[i] = rand();
    }
    return res;
}

void cpy_arr(int* dest, int* inp, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        dest[i] = inp[i];
    }
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

int** func(int** matr, unsigned n, unsigned m, unsigned* new_size)
{
    int** res = NULL;
    int* line = form_line(m);
    cout << endl;
    for (int i=0; i<m; i++) printf("%d\t", line[i]);
    cout << endl << endl;
    unsigned k = 0;
    for (int i=0; i<n; i++, k++)
    {
        res = (int**)realloc(res, sizeof(int*) * (k+1));
        res[k] = (int*)malloc(sizeof(int) * m);
        cpy_arr(res[k], matr[i], m);
        if ( (i+1) % 2 == 0)
        {
            k++;
            res = (int**)realloc(res, sizeof(int*) * (k+1));
            res[k] = (int*)malloc(sizeof(int) * m);
            cpy_arr(res[k], line, m);
        }
    }
    free(line);
    *new_size = k;
    return res;
}

int main()
{

    unsigned n, m;
    cin >> n >> m;
    int** matr = form_matr(n,m);
    print_matr(matr, n, m);
    unsigned k;
    matr = func(matr, n, m, &k);
    print_matr(matr, k, m);
    delete_matr(matr, n);
}
