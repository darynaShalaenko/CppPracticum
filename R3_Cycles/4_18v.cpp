#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    double x;
    cout << "n = ";
    cin >> n;
    cout << "x = ";
    cin >> x;
    vector <double> arr_x;
    double pow1 = -1, x_k = x;
    for (int i = 1; i <= n; i++){
        arr_x.push_back(pow1 * x_k / i);
        pow1 *= -1;
        x_k *= x;
    }
    for (int i = 0; i < arr_x.size(); i++)
        cout << arr_x[i] << ' ';
    cout << endl;
}