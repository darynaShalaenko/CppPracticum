
 <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    cout.fill('=');
    cout.width(56);
    cout << endl << "" << endl;
    int j, k;
    for (int i=1; i<=n; i += j)
    {

        for (j=0, k=i; j<8 && k<=n; j++, k++)
        {
            cout.fill(' ');
            cout.width(7);
            cout.setf(ios::left);
            cout << k;
        }
        cout.fill('-');
        cout.width(56);
        cout << endl << "" << endl;
        for (j=0, k=i; j<8 && k<=n; j++, k++)
        {
            cout.fill(' ');
            cout.width(7);
            cout.precision(3);
            cout.setf(std::ios::fixed);
            cout.setf(ios::left);
            cout << sqrt(k);
        }
        cout.fill('=');
        cout.width(56);
        cout << endl << "" << endl;
    }

}
