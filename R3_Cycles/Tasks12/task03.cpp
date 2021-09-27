#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "n! = ";
    for(int i = 1; i < n; i++) {
        cout << i << "*";
    }
    cout << n << endl;
    return 0;
}