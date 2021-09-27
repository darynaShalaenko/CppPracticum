// Project_ClassComplex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define N 16383
#define pi 3.14

int charToInt(char c) {
    return c - '0';
}

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex() {};
    Complex(double j, double k)
    {
        real = j;
        imaginary = k;
    };
    void output()
    {
        if (imaginary >= 0)
        {
            cout << real << " + " << imaginary << "i";
            cout << endl;
        }
        else 
        {
            cout << real << " - " << abs(imaginary) << "i";
            cout << endl;
        }
    }
    Complex operator+(Complex c2)
    {
        Complex test(this->real + c2.real, this->imaginary + c2.imaginary);
        return test;
    }
    Complex operator-(Complex c2)
    {
        Complex test(this->real - c2.real, this->imaginary - c2.imaginary);
        return test;
    }
    Complex operator*(Complex c2)
    {
        double a = this->real;
        double b = this->imaginary;
        double c = c2.real;
        double d = c2.imaginary;
        Complex test(a * c - b * d, a * d + b * c);
        return test;
    }
    Complex operator*(float c2)
    {
        double a = this->real;
        double b = this->imaginary;
        Complex test(a *c2, b*2);
        return test;
    }
    void conjugate()
    {
        imaginary = -imaginary;
    }
    void setre(double re)
    {
        real = re;
    }
    void setim(double im)
    {
        imaginary = im;
    }

};

double x(int n)
{
    return n;
}

Complex* fur(Complex x[N])
{
    double M = N;
    M = M * M;
    Complex* X = new Complex[N];
    int n, k;

    // Прямое преобразование Фурье
    for (k = 0; k < N; k++)
    {
        X[k].setre(0);
        X[k].setim(0);
        // расчет коэффициента X[k]
        for (n = 0; n < N; n++)
        {
            Complex temp;
            temp.setre(cos(((-2 * pi * k * n) / M )* pi / 180)); temp.setim(-sin(((-2 * pi * k * n )/ M )* pi / 180));
            X[k] = X[k] + (x[k] * temp);


        }
    }

    return X;
}

Complex* ifur(Complex X[N])
{
    double M = N;
    M = M * M;
    Complex* x = new Complex[N];
    int n, k;

    // Прямое преобразование Фурье
    for (k = 0; k < N; k++)
    {
        x[k].setre(0);
        x[k].setim(0);
        // расчет коэффициента X[k]
        for (n = 0; n < N; n++)
        {
            Complex temp;
            temp.setre(cos(((-2 * pi * k * n) / M) * pi / 180)); temp.setim(sin(((-2 * pi * k * n) /M) * pi / 180));
            x[k] = x[k]+(X[k] * temp);


        }
        x[k] = x[k] * (1/(M));

    }
    return x;
}

int main()
{
    string s;
    int count = 0;
    Complex* A = new Complex[16383];
    Complex* B = new Complex[16383];
    Complex* C = new Complex[16383];
    ofstream fout("F.txt");
    if (!fout.is_open())
    {
        cout << "Error";
        return -1;
    }
    for (int i = 0; i < N; i++)
    {
        double k = rand();
        fout << k<< "\n";
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
            sum = sum + charToInt(s[i]) * pow(10, s.length()-c-1);
            c++;
        }
        Complex C(sum, 0);
        A[N - 1 - count] =  C;
        B[count] = C;
        count++;
    }
    A = ifur(A);
    for (int i = 0; i < N; i++)
    {
        Complex c = A[i] * B[i];
        C[i] = c;
    }
    C = fur(C);

    for (int i = 0; i < 10; i++)
    {
        C[i].output();
    }
    fin.close();
    

}
