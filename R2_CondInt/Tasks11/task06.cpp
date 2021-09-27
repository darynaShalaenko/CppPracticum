#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    double cosAlpha = (pow(a, 2) + pow(c, 2) - pow(b, 2))/(2*a*c);
    double cosBeta = (pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b);
    double cosGamma = (pow(b, 2) + pow(c, 2) - pow(a, 2))/(2*b*c);
    double alpha = acos(cosAlpha);
    double beta = acos(cosBeta);
    double gamma = acos(cosGamma);
    double max = alpha;
    if(beta > max) max = beta;
    if(gamma > max) max = gamma;
    cout << "alpha = " << alpha*180/M_PI << endl;
    cout << "beta = " << beta*180/M_PI << endl;
    cout << "gamma = " << gamma*180/M_PI << endl;
    if(max > M_PI/2.0)
        cout << "obtuse triangle" << endl;
    else if(max < M_PI/2.0)
        cout << "acute triangle" << endl;
    else
        cout << "right triangle" << endl;
    return 0;
}