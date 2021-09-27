// Task_3.3.8(e).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
using namespace std;


bool isNearlyZero(double n)
{
    return fabs(n) < 0.000001;
}


double** vvod(double N, double M)
{
    double** mas = new double* [N];
    for (int i = 0; i < N; i++)
    {
        mas[i] = new double[M];
    }
    return mas;
}

void EnterArray(double** mas, double N, double M)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> mas[i][j];
        }
    }
}

void PrintArray(double** mas, double N, double M)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}


void add_column(double** mas, double N, double M)
{
    double n = N , m = M + 1;
    double** mas1 = vvod(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            mas1[i][j] = mas[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "][" << 0 << "] = ";
        cin >> mas1[i][0];
    }
    cout << "Масив після додавання " << endl;
    PrintArray(mas1, n, m);



}

void FreeArray(double** mas, int N)
{
    for (int i = 0; i < N; i++) {
        delete[]mas[i];
    }
    delete[]mas;
}



int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double N, M;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter M: ";
    cin >> M;
    cout << endl;
    double** mas = vvod(N, M);
    EnterArray(mas, N, M);
    cout << "Масив до додавання "<<endl;
    PrintArray(mas, N, M);
    add_column(mas, N, M);
    FreeArray(mas, N);
}

