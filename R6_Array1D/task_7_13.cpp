include <iostream>
#include <stdio.h>

using namespace std;

void inp_arr(int* arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("arr[%d] = ", i);
        cin >> arr[i];
    }
}

void min_max(int* arr, int n, int* min_el, int* max_el)
{
    *min_el = arr[0];
    *max_el = arr[0];

    for (int i=1; i<n; i++)
    {
        if (arr[i] > *max_el) *max_el = arr[i];
        else if (arr[i] < *min_el) *min_el = arr[i];
    }
}

int nearest(int* arr, int n, float mean)
{
    int res = arr[0];
    for (int i=1; i<n; i++)
    {
        if (abs((float)arr[i] - mean) < abs(res-mean)) res = arr[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    inp_arr(arr, n);
    int min_el, max_el;
    min_max(arr, n, &min_el, &max_el);
    float mean = (min_el + max_el) / 2;
    printf("%d %d\n", min_el, max_el);
    int res = nearest(arr, n, mean);
    cout << res << endl;
}
