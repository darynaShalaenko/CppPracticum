
#include <iostream>
#include <cmath>
using namespace std;

//Обчислити гіпотенузу c прямокутного трикутника за катетами a та b

int main()
{
    double a, b, c;
    cout << "Input a,b > 0\n";
    cout << "a: ";
    cin >> a;   
    cout << "\nb: ";
    cin >> b;
    if (a <= 0 || b <= 0) {
        cout << "\nError";
    }
    else {
        c = sqrt(a * a + b * b);
        cout << "\nc= " << c;
    }
    return 0;
}

