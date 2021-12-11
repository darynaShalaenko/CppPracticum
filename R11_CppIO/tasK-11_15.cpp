
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;


int main() {
    long long int *arr = new long long int;
    ifstream fin("12_5_fin.txt");
    int i=0;
    while (!fin.eof()) {
        fin >> arr[i++];
    }
    fin.close();
    for (int j=i-1; j>=0; j--){
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << (double) sqrt(arr[j]) << endl;
    }
    delete[] arr;
}
