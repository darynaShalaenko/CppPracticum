#include <iostream>
#include <stdio.h>

using namespace std;

void inp_arr(int* a, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        printf("a[%d] = ",i+1);
        cin >> a[i];
    }
}

int func(int* a, unsigned n)
{
    int b[n];
    int min_el = a[0] + a[1], tmp;
    for (int i=0; i<n-1; i++)
    {
        tmp = a[i] + a[i+1];
        if (tmp < min_el) min_el = tmp;
        printf("b[%d] = %d\n", i+1, tmp);
    }
    return min_el;
}

int main()
{
    unsigned n;
    cin >> n;
    int a[n];
    inp_arr(a, n);
    int res = func(a, n);
    cout
