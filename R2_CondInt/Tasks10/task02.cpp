#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << endl;
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int c = n % 10;
    if(a != b != c) {
        cout << a << b << c << endl;
        cout << a << c << b << endl;
        cout << b << a << c << endl;
        cout << b << c << a << endl;
        cout << c << a << b << endl;
    }
    else {
        cout << "There ara same digits." << endl;
    }
    return 0;
}
