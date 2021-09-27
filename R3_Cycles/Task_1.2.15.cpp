// Task_1.2.15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

bool isPositive(int n)
{
    if (n >= 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    int n, count = 0;
    bool k = false;
    cin >> n;
    k = isPositive(n);
    while (n != 0)
    {
        cin >> n;
        if (k != isPositive(n) and n!=0)
        {
            count += 1;
        }
        k = isPositive(n);

    }
    cout << count;
}

