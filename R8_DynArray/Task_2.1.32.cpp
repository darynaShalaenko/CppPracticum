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

void EnterArray(double** array, double N, double M)
{
    int m = 10;
    int n = 10;

    int s = 1;
    for (int y = 0; y < n; y++) {
        array[0][y] = s;
        s++;
    }
    for (int x = 1; x < m; x++) {
        array[x][n - 1] = s;
        s++;
    }
    for (int y = n - 2; y >= 0; y--) {
        array[m - 1][y] = s;
        s++;
    }
    for (int x = m - 2; x > 0; x--) {
        array[x][0] = s;
        s++;
    }
    int c = 1;
    int d = 1;

    while (s < m * n) {
      

        //Движемся вправо.
        while (array[c][d + 1] == 0) {
            array[c][d] = s;
            s++;
            d++;
        }

        //Движемся вниз.
        while (array[c + 1][d] == 0) {
            array[c][d] = s;
            s++;
            c++;
        }

        //Движемся влево.
        while (array[c][d - 1] == 0) {
            array[c][d] = s;
            s++;
            d--;
        }

        while (array[c - 1][d] == 0) {
            array[c][d] = s;
            s++;
            c--;
        }
    }
    array[n / 2][m / 2] = s;

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cout << array[x][y] << " ";
        }
        cout << endl;
    }

}


void FreeArray(int** mas, int N)
{
    for (int i = 0; i < N; i++)
        delete[]mas[i];

    delete[]mas;
}



int main()
{
    int N = 50, M;
    M = N;
    cout << endl;
    double** mas = vvod(N, M);
    EnterArray(mas, N, M);

}


