#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    const char* sep = "=========================================================================================================";

    cout << sep << endl;


    for (int i=1; i<=n; i++)
    {
        cout.fill(' ');
        cout.width(7);
        cout.setf(ios::left);
        cout << i;
    }

    cout << endl << sep << endl;

    for (int i=1; i<=n; i++)
    {
        cout.fill(' ');
        cout.width(7);
        cout.precision(3);
        cout.setf(ios::left);
        cout << sqrt(i);
    }
}
