#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << endl;
    if(a > b)
        cout << "a > b" << endl;
    else if(a < b)
        cout << "a < b" << endl;
    else
        cout << "a = b" << endl;
    return 0;
}
