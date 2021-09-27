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


void del_all(double** mas, double N, double M)
{
    int max = -1000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mas[i][j] > max)
            {
                max = mas[i][j];
            }
        }
      
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (mas[i][j] == max)
                {
                    for (int p = i; p < N - 1; p++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            mas[p][j] = mas[p + 1][j];
                        }

                    }
                    N--;
                    for (int p = 0; p < N ; p++)
                    {
                        for (int x = j; x < M-1; x++)
                        {
                            cout << x << endl;
                            mas[p][x] = mas[p][x+1];
                        }

                    }
                    M--;
                }

            }
        }
    }
    cout << "Масив після видалення " << endl;
    PrintArray(mas, N, M);



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
    cout << "Масив до видалення " << endl;
    PrintArray(mas, N, M);
    del_all(mas, N, M);
    FreeArray(mas, N);
}

