#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    double eps = 1e-7;
    double a,b,t,p;   
    a = 1;
    b = 1.0/sqrt(2);
    t = 1.0/4;
    p = 1;
    double pi = 0, pre_pi = -1;
    while(abs(pi - pre_pi) > eps){
        pre_pi = pi;
        pi = (a * b) * (a * b) / 4 / t;
        double ax = (a + b) / 2;
        double bx = sqrt(a * b);
        double tx = t - p*(a - ax)*(a - ax);
        double px = 2.0 * p;
        a = ax;
        b = bx;
        t = tx;
        p = px;
    }
    cout << "pi = ";
    cout << pi << endl;

    //ряд, который дан в условие не правильный, поэтому число пи не получилось
}

