// Problem 1.19(ж).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

bool isNearlyZero(float x)
{
    return fabs(x) < 0.0000001;
}
float fun(float x, float a)
{
    if (isNearlyZero(a))
    {
        return x;
    }
    else if (a < 0)
    {
        return -(log(1 - a * (x + a))) / a;
    }
    else
    {
        return ((exp(a * x) - 1) / a) + a;
    }
}


float fun_d(float x, float a)
{
    if (isNearlyZero(a))
    {
        return 1;
    }
    else if (a < 0)
    {
        return 1 / (1 - x * a - a * a);
    }
    else
    {
        return exp(a * x);
    }
}

int main()
{
    float x, a = 0;
    cin >> x;
    cin >> a;
    cout << fun(x, a)<< endl;
    cout << fun_d(x, a)<< endl;
}


