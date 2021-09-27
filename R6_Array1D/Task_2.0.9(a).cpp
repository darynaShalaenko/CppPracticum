// Task_2.0.9(a).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


bool sq(int a)
{
    int k = 1;
    while (k < a)
    {
        if (k * k == a)
        {
            return true;
        }
        k++;
    }
    return false;
}

int main()
{
    int N;
    int count = 0;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        int a = 0;
        cout << "a" << i + 1 << "= ";
        cin >> a;
        arr[i] = a;
    }
    for (int i = 0; i < N; i++)
    {
        if (sq(arr[i]))
        {
            count++;
        }
    }
    cout << count;

}

