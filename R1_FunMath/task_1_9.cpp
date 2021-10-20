include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float r, a, b, c;
    do {
        cout << "Ââåäèòå ðàäèóñ âïèñàííîé îêðóæíîñòè" << endl;
        cin >> r;
    } while (r <= 0);

    do {
        cout << "Ââåäèòå óãëû" << endl;
        cin >> a >> b >> c;
    } while (abs(a+b+c - 180) >= 0.0001);

    float s = (1/tan(M_PI*a/360) + 1/tan(M_PI*b/360) + 1/tan(M_PI*c/360))*r*r;

    cout << "s = " << s << endl;
}
