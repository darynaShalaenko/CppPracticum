#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Task 7" << endl;
    string s;
    cin >> s;
    string s1 = s.substr(0, 10);
    string s2 = s.substr(10, 10);
    double a = stod(s1);
    double b = stod(s2);
    double sum = a + b;
    cout << "Sum is: " << sum << endl;
    return 0;
}