#include <iostream>
#include <cmath>
using namespace std;

double calc(int n) {
    double res = sqrt(3*n);
    for(int i = (n - 1); i > 0; i--) {
        res = sqrt(3*i + res);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Result: " << calc(n) << endl;
    return 0;
}