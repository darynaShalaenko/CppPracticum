
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    float v_0 = 1;
    float v_1 = 0.3;
    float v_n, v_n1, v_n2;//v(n), v(n-1), v(n-2);
    v_n1 = v_1;
    v_n2 = v_0;
    for (int i = 2; i <= n; i++) {
        v_n = (i + 2) * v_n2;
        v_n2 = v_n1;
        v_n1 = v_n;
    }
    cout << "V(n) = " << v_n;
}


