// Task_3.1.19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    string a, b = ",.3+", c ="";
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[1])
        {
            break;
        }
        if (a[i] == b[0])
        {
            a[i] = c[0];
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[2])
        {
            a[i] = b[3];
        }
    }
    cout << a;
}
