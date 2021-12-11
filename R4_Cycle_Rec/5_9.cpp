#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    double v[n + 1],u[n + 1];
    v[0] = 1;
    v[1] = 1;
    u[0] = 0;
    u[1] = 0;
    
    for (int i = 2; i <= n; i++){
        v[i] = (u[i - 1] - v[i - 1]) / (abs(u[i - 2] + v[i - 1]) + 2);
        u[i] = (u[i - 1] - u[i - 2] * v[i - 1] - v[i - 2]) / (1 + u[i - 1] * u[i - 1] + v[i - 1] * v[i - 1]);
    }
    cout << "v[n] = " << v[n] << endl;

}

