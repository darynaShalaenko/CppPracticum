#include <iostream>
#include <cmath>
using namespace std;

double calc(int n) {
    double res = sqrt(2);
    for(int i = 1; i < n; i++) {
        res = sqrt(2 + res);
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