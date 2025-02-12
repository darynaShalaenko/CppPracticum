//
// Created by Pavel Melnychuk on 22.05.2020.
//

#include<iostream>

using namespace std;

class Poly
{
protected:
  int n;
  double *koef;

public:
  Poly(){}

  Poly(int an)
  {
    n = an;
    koef = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        koef[i] = 0;
    }
  }

  Poly(const Poly &f)
  {
      n = f.n;
      koef = new double[n + 1];
      for (int i = 0; i <= n; i++)
          koef[i] = f.koef[i];
  }

  ~Poly()
  {
      delete []koef;
  }

  int getn()
  {
      return n;
  }

  double getkoef(int i)
  {
      if (i <= n)
          return koef[i];
      else
          return 0.0;
  }

  Poly operator+(const Poly &t)
  {
      if (n >= t.n)
      {
          Poly z = *this;
          for (int i = 0; i <= n; i++)
              z.koef[i] = t.koef[i] + koef[i];
          return z;
      }
      else
      {
          Poly z = t;
          for (int i = 0; i <= n; i++)
              z.koef[i] = t.koef[i] + koef[i];
          return z;
      }
  }

  Poly operator-(const Poly &t)
  {
      int i;
      if (n >= t.n)
      {
          Poly z = *this;
          for (i = 0; i <= t.n; i++)
              z.koef[i] = koef[i] - t.koef[i];
          return z;
      }
      else
      {
          Poly z(t.n);
          for (i = 0; i <= n; i++)
              z.koef[i] = -t.koef[i] + koef[i];
          for (i = n + 1; i <= t.n; i++)
              z.koef[i] = -t.koef[i];
          return z;
      }
  }

  Poly operator*(const Poly &t)
  {
      int i,j, s=0;
      Poly y(n+t.n);
      for (i = 0; i <= n; i++)
          for (j = 0; j <= t.n; j++)
              y.koef[i + j] += koef[i]*t.koef[j];
      return y;
  }

  friend ostream &operator<< (ostream &s, const Poly &p)
  {
    int i;
    int n = 0;
    for (i = 0; i <= p.n; i++)
    {
        if (p.koef[i] != 0)
            n++;
    }
    if (n > 0)
    {
        if (p.koef[0] != 0)
        {
            s << p.koef[0];
        }
        for (i = 1; i <= p.n; i++)
        {
            if (p.koef[i] < 0)
            {
                if(p.koef[i]!=-1)
                    s << p.koef[i] << "x**" << i;
                else
                    s << "-" << "x**" << i;
            }
            else
            {
                if (p.koef[i] != 0)
                {
                    if(p.koef[i] != 1)
                        s << "+" << p.koef[i] << "x**" << i;
                    else
                        s<< "+" << "x**" << i;
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

  friend istream &operator>> (istream &s, Poly &p)
  {
      for (int i = 0; i <= p.n; i++)
      {
          s >> p.koef[i];
      }
      return s;
  }

};


int main()
{
    int n, m;
    cout << "Poly a power: ";
    cin >> n;
    cout << "Poly b power: ";
    cin >> m;

    Poly a(n);
    Poly b(m);
    Poly res1, res2, res3;

    cout << "Poly a koefs:";
    cin >> a;
    cout << "Poly b koefs:";
    cin >> b;
    cout << "Poly a =         " << a << '\n';
    cout << "Poly b =         " << b << '\n';
    cout << "a + b - a * b =  " << (res1 = a + b - a * b) << '\n';
}