#include <iostream>
#include <cmath>
using namespace std;

double fact(int n)
{
    double res = 1;
    for(int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}


double rec(double x)
{
    int count;
    double eps = 0.00001;
    double ak;
    double s;
    s = 0;
    ak = 1;
    count = 0;
    while (abs(ak) >= eps && abs(x) < 1)
    {
        ak = pow(x, 2*count)/(fact(2*count));
        s += ak;
        count++;
    }
    return s;
}

int main()
{
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << rec(x);

}
