#polynom
#methods of input, output, multiply, addition, derivative isolation



#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Polynom
{
public:
    int n;
    double *koef; 
    Polynom();
    Polynom(int an);
    Polynom(const Polynom &); 
    ~Polynom();
    int getn(); 
    double getkoef(int); 
    Polynom operator+(const Polynom &);  
    Polynom operator-(const Polynom &);  
    Polynom operator*(const Polynom &);
    Polynom operator=(const Polynom &);   
    Polynom derivative();
    Polynom integral();
    friend ostream &operator<< (ostream &s, const Polynom &c);
    friend istream &operator >> (istream &s, Polynom &c);
    double &operator()(int i)
    {
        return koef[i];
    }
};
Polynom::Polynom() 
{
    koef = NULL;
}

Polynom::~Polynom()
{
    delete[]koef;
}
Polynom::Polynom(int an)
{
    int i;
    n = an;
    koef = new double[n + 1];
    for (i = 0; i <= n; i++)
    {
        koef[i] = 0;
    }
}
Polynom::Polynom(const Polynom &f)
{
    n = f.n;
    koef = new double[n + 1];
    for (int i = 0; i <= n; i++)
        koef[i] = f.koef[i];
}
int Polynom::getn() 
{
    return n;
}
double Polynom::getkoef(int i) 
{
    if (i <= n)
        return koef[i];
    else
        return 0.0;
}
Polynom Polynom::operator-(const Polynom &t)
{
    int i;
    if (n >= t.n)//А>B
    {
        Polynom Z = *this;
        for (i = 0; i <= t.n; i++)
            Z.koef[i] = koef[i] - t.koef[i];
        return Z;
    }
    else//B>A
    {
        Polynom Z(t.n);
        for (i = 0; i <= n; i++)
            Z.koef[i] = -t.koef[i] + koef[i];
        for (i = n + 1; i <= t.n; i++)
            Z.koef[i] = -t.koef[i];
        return Z;
    }
}
Polynom Polynom::operator+(const Polynom &t)
{
    int i;
    if (n >= t.n)//A>B
    {
        Polynom Z=*this;
        for (i = 0; i <= n; i++)
            Z.koef[i] = koef[i] + t.koef[i];
        return Z;
    }
    else//A<B
    {
        Polynom Z=t;
        for (i = 0; i <= n; i++)
            Z.koef[i] = t.koef[i] + koef[i];
        return Z;
    }
}
Polynom Polynom::operator*(const Polynom &t)
{
    int i,j, s=0;
    Polynom Y(n+t.n);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= t.n; j++)
            Y.koef[i + j] += koef[i]*t.koef[j];
    return Y;
}
Polynom Polynom::operator = (const Polynom &t) 
{
    if(this!=&t)
    {
        delete[] koef;
        n = t.n;
        koef = new double[n + 1];
        for (int i = 0; i <= n; i++)
            koef[i] = t.koef[i];
    }
    return *this;
}
istream &operator>>(istream &s, Polynom &c)
{
    int i;
    for (i = 0; i <= c.n; i++)
    {
        s >> c.koef[i];
    }
    return s;
}
ostream &operator<<(ostream &s, const Polynom &c)
{
int i, n=0;
for (i = 0; i <= c.n; i++)
{
    if (c.koef[i] != 0)
        n++;
}
if (n != 0)
{
    if (c.koef[0] != 0)
    {
        s << c.koef[0];
    }
    for (i = 1; i <= c.n; i++)
    {
        if (c.koef[i] < 0)
        { 
            if(c.koef[i]!=-1)
                s << c.koef[i] << "X^" << i; 
            else
                s << "-" << "X^" << i;
        }
        else
        {
            if (c.koef[i] != 0)
            {
                if(c.koef[i] != 1)
                    s << "+" << c.koef[i] << "X^" << i;
                else
                    s<< "+" << "X^" << i;
            }
        }
    }
s << '\n';
}
else
{
    s << 0;
}
return s;
}
Polynom Polynom::derivative()
{
    int i;
    Polynom Z(n - 1);
    for (i = 0; i <=n-1; i++)
    {
        Z.koef[i] =(i+1)*koef[i +1];
    }
    return Z;
}

void main()
{
    setlocale(LC_ALL, "");
    int n, m;
    cout << "Введите степень полинома A и степень полинома B:" << '\n';
    cin >> n>>m;
    Polynom A(n), B(m), D, K, Y;
    cout << "Введите коэфициенты полинома A:" << '\n';
    cin >> A;
    cout << "Введите коэфициенты полинома B:" << '\n';
    cin >> B;
    cout << setw(17) << "Многочлен А:" << setw(5) << A << '\n';
    cout << setw(17) << "Многочлен B:" << setw(5) << B << '\n';
    cout << setw(17) << "Многочлен D=A+B:" << setw(5) << (D = A + B) << '\n';
    cout << setw(17) << "Многочлен K=A-B:" << setw(5) << (K = A - B) << '\n';
    cout << setw(17) << "Производная от A:" << setw(5)<< A.derivative() << '\n';
    cout << setw(17) << "Многочлен Y=A*B:" << setw(5) << (Y = A*B)<< '\n';
    system("pause");
}
