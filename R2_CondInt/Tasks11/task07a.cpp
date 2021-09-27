#include <iostream>
#include <cmath> /* for std::abs(double) , sqrt */
#include <limits>
using namespace std;

inline bool isEqual(double x, double y)
{
  const double epsilon = numeric_limits<double>::epsilon();/* some small number such as 1e-5 */
  return abs(x - y) <= epsilon * abs(x);
  // see Knuth section 4.2.2 pages 217-218
}

inline bool isZero(double x)
{
  const double epsilon = numeric_limits<double>::epsilon();/* some small number such as 1e-5 */
  return abs(x) <= epsilon * abs(x);
  // see Knuth section 4.2.2 pages 217-218
}

int main() {
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double D = pow(b, 2) - 4*a*c;
    if(D < 0) {
        cout << "No solutions." << endl;
    }
    else if(D == 0) {
        cout << "One solution: " << endl;
        double x1 = (-1*b)/(2*a);
        cout << "x1 = " << x1 << endl;
    }
    else {
        cout << "Two solutions: " << endl;
        double x1 = (-1*b + sqrt(D))/(2*a);
        double x2 = (-1*b - sqrt(D))/(2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
}
