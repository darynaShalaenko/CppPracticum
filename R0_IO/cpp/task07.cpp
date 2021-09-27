#include <iostream>
using namespace std;

int main() {
    cout << "Task 0.7" << endl;
    double T = 1.0 + 1.0 / 3.0;
    T = 7.0 + 1.0 / T;
    T = 4.0 + 1.0 / T;
    T = 365 + 1 / T;
    cout << "T = " << T << endl;
    return 0;
}
