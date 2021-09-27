
#include <iostream>
#include <cmath>
using namespace std;

double calculate(double x)
{
    double th = (exp(x) - exp(-x)) / (exp(x) + exp(-x));
    return th;
}

double derivative(double x)
{
    double th =calculate(x);
    double numerator = (exp(x) - exp(-x));
    double denominator = (exp(x) + exp(-x));
    double derivative_exp = exp(x);
    double derivative_exp_ = exp(x)*(-1);
    double derivative_n = derivative_exp- derivative_exp_;
    double derivative_d = derivative_exp + derivative_exp_;
    double f = (derivative_n * denominator - numerator * derivative_d) / (denominator * denominator);
    return f;
}

int main()
{
    double x;
    cin >> x;
    cout << calculate(x) << "\n";
    cout << derivative(x) << "\n";
    return 0;
}

