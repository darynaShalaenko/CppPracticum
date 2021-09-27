#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cout << "Enter numbers: " << endl;
    cin >> a;
    cin.ignore();
    cin >> b;
    cin.ignore();
    cin >> c;
    long long res = a*b*c;
    cout << "Composition: " << res << endl;
    return 0;
}
