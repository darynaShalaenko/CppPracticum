#include <iostream>
#include <cmath>
using namespace std;

float myFunction(float eps){
    int k=0;
    double S;
    while (1/pow(k,4)> eps) {
        k += 1;
        S += 1/pow(k,4);
    }
    return sqrt(sqrt(90*S));
}
int main()
{
    float eps;
    cout << "eps=" ;
    cin >> eps;
    cout <<"Approximation of pi: " << myFunction(eps)<< endl;
    return 0;
}
