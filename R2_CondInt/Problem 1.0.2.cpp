// Problem 1.0.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void resh(int a, int b, int c)
{
    cout << a << b << c << endl;
    cout << b << a << c << endl;
    cout << c << a << b << endl;
    cout << a << c << b << endl;
    cout << b << c << a << endl;
    cout << c << b << a << endl;
}

int main()
{
    int x, a, b, c;
    cin >> x;
    a = x % 10;
    b = x / 10;
    b = b % 10;
    c = x / 100;
    if (a != b and b != c and a != c)
    {
        resh(a, b, c);
    }
    else
    {
        cout << ("Numbers are not unique");
    }
}

