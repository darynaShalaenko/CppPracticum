

#include <iostream>
#include <math.h>
using namespace std;

float fun(float x, int n)
{
    float sum = x;
    if (n == 1)
    {
        return sum;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            sum += pow(x, i * i);
        }
        return sum;
    }
}

int main()
{
    float x = -1;
    int n = 5;
    cout << fun(x,n);
}


