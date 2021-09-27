#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
using namespace std;

void variation(long double *Array, long double &v, long double &average, int &n,int &counter)
{
    long double sum = 0; // Сума елементів масиву
    long double sum_qd = 0; // Сума квадратичних відхилень від середнього арифметичного
    long double single_qd;
    for (int i = 0; i < n; i++)
    {
        sum += Array[i];
    }
    average = sum / n; // Середнє арифметичне
    for (int i = 0; i < n; i++)
    {
        single_qd = (Array[i] - average);
        single_qd *= single_qd;
        sum_qd += single_qd;
    }
    v = sqrt(sum_qd / n); // Середнє квадратичне відхилення
    counter++; // Перше завдання
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int static counter; // Перше завдання
    int n;
    long double v = 0, av = 0;

    cout << "n = ";
    cin >> n;

    long double* Array = new long double[n];

    for (int i = 0; i < n;i++)
    {
        Array[i] = rand() % 50;
        cout << Array[i]<<"\t";
    }
    cout << endl;

    variation(Array, v, av, n, counter);
    cout << "Function calls number: " << counter << endl; // Перше завдання

    variation(Array, v, av, n, counter);
    cout << "Function calls number: " << counter << endl;

    cout << "Quadratic deviation = " << v << endl << "Variation = " << v / av * 100 << "%" << endl;
    delete[]Array;
}


