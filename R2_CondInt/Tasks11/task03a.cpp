#include <iostream>
using namespace std;

int main() {
    double x, y, z;
    cout << "Enter x, y and z: ";
    cin >> x >> y >> z;
    auto* arr = new double[3];
    arr[0] = x + y + z;
    arr[1] = x*y - x*z + y*z;
    arr[2] = x*y*z;
    double max = arr[0];
    for(int i = 1; i < 3; i++) {
        if(arr[i] > max) max = arr[i];
    }
    cout << "max() = " << max << endl;
    return 0;
}
