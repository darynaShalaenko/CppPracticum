#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    cout << "x = ";
    double x;
    cin >> x;
    if (abs(x) >= 1){
        cout << "error! |x| < 1 !" << endl;
        return 0;
    }

    double y = 1, pre_y = 0;
    double eps = 1e-9;
    double u = -1, d = 2;
    int i = 1;
    double x_k = x;
    while (abs(y - pre_y) > eps){
        pre_y = y;
        y += x_k * u / d;
        x_k *= x;
        i+= 2;
        u *= -1 * i;
        d *= i + 1;
    }
    cout << y << endl;
}