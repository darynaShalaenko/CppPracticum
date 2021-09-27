#include <iostream>
using namespace std;

/* Обчислити кінетичну енергію тіла масою m, що рухайться зі швидкістю v до Землі.
*/
int main()
{
    double m, v, E;
    cout << "Input mass: ";
    cin >> m;
    cout << "Input speed: ";
    cin >> v;
    E = (m * v * v) / 2;
    cout << "E = " << E;
}

