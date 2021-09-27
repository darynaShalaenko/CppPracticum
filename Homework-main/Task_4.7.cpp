// Task_4.6(в).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Car
{
    double cost;
    int age;
};

Car EnterCar(Car cr)
{
    cout << "Enter age: ";
    cin >> cr.age;
    cout << "Enter cost: ";
    cin >> cr.cost;
    return cr;
}

void PrintCar(Car* a, int n)
{
    double sum = 0;
    double count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].age > 5)
        {
            sum = sum + a[i].cost;
            count++;
        }
    }
    cout << sum / count;

}

int main()
{
    int n = 0;
    cout << "Enter Count: ";
    cin >> n;
    Car* a = new Car [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = EnterCar(a[i]);
    }
    PrintCar(a, n);
}


