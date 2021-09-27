#include <iostream>
#include <math.h>
using namespace std;

class Exception
{
private:
    string m_error;

public:
    Exception() {};
    Exception(string j)
    {
        m_error = j;
    };

    string getError() { return m_error; }
};
class ExceptionRange : private Exception
{
public:
    Exception range()
    {
        Exception test("Wrong range");
        return test;
    }

};
class ExceptionZero : private Exception
{
public:
    Exception zero()
    {
        Exception test("Denominator = 0");
        return test;
    }

};

class Byte3
{
private:
    int x;
public:
    Byte3() {};
    Byte3(int j)
    {
        try 
        {
            
            if (-pow(2,23)> j or pow(2,23) <= j)
                throw "Wrong range"; 
            x = j;
        }
        catch (string exception) 
        {
            cerr << "Error: " << exception << '\n';
        }
    };
    void input()
    {
        int k;
        cout << "x =";
        cin >> k ;
        try 
        {
            
            if (-pow(2, 23) > k or pow(2, 23) <= k)
            {
                ExceptionRange t;
                throw t;
            }
            x = k;
        }
        catch (string exception) 
        {
            cerr << "Error: " << exception << '\n';
        }
    }

    void output()
    {
        cout << "x = " << x << endl;
    }


    int get_x()
    {
        return x;
    }
    Byte3 operator+(Byte3 c2)
    {
        int res = this->x + c2.x;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator+(int c2)
    {
        int res = this->x + c2;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator-(Byte3 c2)
    {
        int res = this->x - c2.x;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator-(int c2)
    {
        int res = this->x - c2;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator*(Byte3 c2)
    {
        int res = this->x * c2.x;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator*(int c2)
    {
        int res = this->x * c2;
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator/(Byte3 c2)
    {
        int res = pow(2, 23) + 1;
        try
        {

            if (c2.x == 0)
            {
                ExceptionZero t;
                throw t;
            }
            int res = this->x / c2.x;
        }
        catch (ExceptionZero exception)
        {
            cerr << "Error: " << exception.zero().getError() << '\n';
        }
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
    Byte3 operator/(int c2)
    {
        int res = pow(2, 23) + 1;
        try
        {

            if (c2 == 0)
            {
                ExceptionZero t;
                throw t;
            }
            int res = this->x / c2;
        }
        catch (ExceptionZero exception)
        {
            cerr << "Error: " << exception.zero().getError() << '\n';
        }
        try
        {

            if (-pow(2, 23) > res or pow(2, 23) <= res)
            {
                ExceptionRange t;
                throw t;
            }
            Byte3 test(res);
            return test;
        }
        catch (ExceptionRange exception)
        {
            cerr << "Error: " << exception.range().getError() << '\n';
        }
    }
};


int main()
{
    Byte3* k = new Byte3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        Byte3 t(p);
        k[i] = t;
    }
    Byte3 sum(0);
    for (int i = 0; i < n; i++)
    {
        sum = sum + k[i];
    }
    cout << sum.get_x() << "\n";
    int k1;
    int n1;
    cin >> n1;
    cin >> k1;
    Byte3 g(k1);
    for (int i = 0; i < n1 - 1; i++)
    {
        g = g *k1;
    }
    cout << g.get_x();
}
