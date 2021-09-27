// Project_Classcomplex <double>.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <complex>

using namespace std;
#define N 16383
#define pi 3.14

int charToInt(char c) {
    return c - '0';
}


double x(int n)
{
    return n;
}

complex <double>* fur(complex <double> x[N])
{
    double M = N;
    M = M * M;
    complex <double>* X = new complex <double>[N];
    int n, k;

    // Прямое преобразование Фурье
    for (k = 0; k < N; k++)
    {
        X[k].real(0);
        X[k].imag(0);
        // расчет коэффициента X[k]
        for (n = 0; n < N; n++)
        {
            complex <double> temp;
            temp.real(cos(((-2 * pi * k * n) / M) * pi / 180)); temp.imag(-sin(((-2 * pi * k * n) / M) * pi / 180));
            X[k] = X[k] + (x[k] * temp);


        }
    }

    return X;
}

complex <double>* ifur(complex <double> X[N])
{
    double M = N;
    M = M * M;
    complex <double>* x = new complex <double>[N];
    int n, k;

    // Прямое преобразование Фурье
    for (k = 0; k < N; k++)
    {
        x[k].real(0);
        x[k].imag(0);
        // расчет коэффициента X[k]
        for (n = 0; n < N; n++)
        {
            complex <double> temp;
            temp.real(cos(((-2 * pi * k * n) / M) * pi / 180)); temp.imag(sin(((-2 * pi * k * n) / M) * pi / 180));
            x[k] = x[k] + (X[k] * temp);


        }
        x[k] = x[k] * (1 / (M));

    }
    return x;
}

int main()
{
    string s;
    int count = 0;
    complex <double>* A = new complex <double>[16383];
    complex <double>* B = new complex <double>[16383];
    complex <double>* C = new complex <double>[16383];
    ofstream fout("F.txt");
    if (!fout.is_open())
    {
        cout << "Error";
        return -1;
    }
    for (int i = 0; i < N; i++)
    {
        double k = rand();
        fout << k << "\n";
    }
    fout.close();
    ifstream fin("F.txt");
    if (!fin.is_open())
    {
        cout << "Error";
        return -1;
    }
    while (getline(fin, s))
    {
        double sum = 0;
        int c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum = sum + charToInt(s[i]) * pow(10, s.length() - c - 1);
            c++;
        }
        complex <double> C(sum, 0);
        A[N - 1 - count] = C;
        B[count] = C;
        count++;
    }
    A = ifur(A);
    for (int i = 0; i < N; i++)
    {
        complex <double> c = A[i] * B[i];
        C[i] = c;
    }
    C = fur(C);

    for (int i = 0; i < 10; i++)
    {
        cout << C[i] << endl;
    }
    fin.close();


}
