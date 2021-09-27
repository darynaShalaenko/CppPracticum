#include <iostream>
using namespace std;

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
    cout << "n!! = " << doubleFactorial(n) << endl;
    return 0;
}
