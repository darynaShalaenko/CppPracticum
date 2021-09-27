

#include <iostream>
using namespace std;

int main()
{
    int k;
    float x;
    cin >> x >> k;
    float result = 1;
    for (int i =0; i <= k; i++) {
        if (i == 0) {
            result *= x;
        }
        else {
            result *= -((x * x)) / ((2 * i) * (2 * i + 1));
        }
    }
    cout << "Res: " << result;
}

