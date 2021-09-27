// Task_4.6(в).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Obj
{
    double mass;
    double volume;
};

Obj EnterObj(Obj cr)
{
    cout << "Enter mass(kg): ";
    cin >> cr.mass;
    cout << "Enter volume(m^3): ";
    cin >> cr.volume;
    return cr;
}

void PrintObj(Obj* a, int n)
{
    double m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].mass/a[i].volume > m)
        {
            m = a[i].mass / a[i].volume;
        }
    }
    cout << m;

}

int main()
{
    int n = 0;
    cout << "Enter Count: ";
    cin >> n;
    Obj* a = new Obj[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = EnterObj(a[i]);
    }
    PrintObj(a, n);
}


