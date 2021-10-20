// Task_2.0.13(a).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

float fun(int n, float x)
{
    float t0 = 1, t1 = x, tn = 0;
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            tn = 2 * x * t1 - t0;
            t0 = t1;
            t1 = tn;
        }
        return tn;
    }
}

float kof(int k, float x)
{
    return fun(k, x);
}

int main()
{
    int N;
    cin >> N;
    float x;
    cin >> x;
    cout << fun(N, x) << endl;
    cout << kof(4, x);
}

