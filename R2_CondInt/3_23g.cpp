#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double fun(double a,double x){
    if (x < 0)
        return a * (pow(M_E,x) - 1);
    return 0;
}

double def(double a,double x){
    if (x < 0)
        return a * pow(M_E,x);
    return 0;
}

int main(){
    double a,x;
    cout << "a = ";
    cin >> a;
    cout << "x = ";
    cin >> x;

    cout << "leakyReLu(a,x) = " << fun(a,x) << endl;
    cout << "deff leakyReLu(a,x) = " << def(a,x) << endl;
}