#include <iostream>
#include <math.h>
using namespace std;

float rek(int n)
{
    float a0= 1, a1 = 2;
    float b0 = 5, b1 = 5, bn = 0;
    float s = 0;
    for (int i = 1; i <= n;i++)
    {
        s += pow((a1 / b1), i);
        bn = b1;
        a0 = a1;
        b1 = b0 * b0 - a1;
        a1 = b0 + b1 / 2;
        b0 = bn;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << rek(n);

}