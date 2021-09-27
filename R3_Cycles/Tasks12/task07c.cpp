#include <iostream>
using namespace std;

int factorial(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int doubleFactorial(int n) {
    int res = 1;
    if(n % 2 == 0) {
        for(int i = 2; i <= n; i += 2) {
            res *= i;
        }
    }
    else {
        for(int i = 1; i <= n; i += 2) {
            res *= i;
        }
    }
    return res;
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int res = factorial(n) * doubleFactorial(n) * doubleFactorial(n+1);
    cout << "n!n!!(n + 1)!! = " << res << endl;
    return 0;
}
