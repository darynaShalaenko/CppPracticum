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
    int s = a + b + c;
    int r = 100*a + 10*b + c;
    cout << "Units: " << a << endl;
    cout << "Dozens: " << b << endl;
    cout << "Hundreds: " << c << endl;
    cout << "Sum of digits: " << s << endl;
    cout << "Reversed: " << r << endl;
    return 0;
}
