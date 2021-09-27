#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double two_x = 2*x;
    double four_x2 = two_x * two_x;
    double eight_x3 = four_x2 * two_x;
    double sixteen_x4 = four_x2 * four_x2;
    double y = sixteen_x4 + eight_x3 + four_x2 + two_x + 1;
    cout << "y = " << y << endl;
    return 0;
}
