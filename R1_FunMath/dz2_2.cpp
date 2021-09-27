
#include <iostream>
using namespace std;

float ReLu(float x)
{
    if (x >= 0) { return x; }
    else { return 0; }
}
int derivative(float x) {
    if (ReLu(x)> 0) { return 1; }
    else { return 0; }
}
int main() {
    float x = -2;
    cout << ReLu(x)<<"\n";
    cout << derivative(x);
}