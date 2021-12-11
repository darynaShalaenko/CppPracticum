#include <iostream>
#include <math.h>

using namespace std;

float gauss(float x){
    float res;
    res = exp((-1)*x*x);
    return res;
}

float gauss_1(float x){
    float res;
    res = (-2)*x*gauss(x);
    return res;
}

int main(){
    float x;
    cout << "x = ";
    cin >> x;
    cout << "f(x) = " << gauss(x) << endl;
    cout << "f'(x) = " << gauss_1(x);
}
