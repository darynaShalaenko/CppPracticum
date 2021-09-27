#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Task 5" << endl;
    string as, bs, cs;
    cout << "Enter a, b and c:" << endl;
    cin >> as >> bs >> cs;
    as = as.substr(2);
    bs = bs.substr(2);
    cs = cs.substr(2);
    double a = stoi(as);
    double b = stoi(bs);
    double c = stoi(cs);
    double arithm = (a + b + c)/3.0;
    double harm = 3.0/(1.0/a + 1.0/b + 1.0/c);
    cout << scientific;
    cout << "Scientific representation:" << endl;
    cout << "Arithmetic mean: " << arithm << endl;
    cout << "Harmonic mean: " << harm << endl;
    cout << endl;
    cout << defaultfloat;
    cout << "Default representation:" << endl;
    cout << "Arithmetic mean: " << arithm << endl;
    cout << "Harmonic mean: " << harm << endl;
    return 0;
}