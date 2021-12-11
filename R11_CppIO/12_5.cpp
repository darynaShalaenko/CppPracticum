#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    long long a;
    vector <long long> arr;
    while (cin >> a){
        arr.push_back(a);
    }
    for (int i = arr.size() - 1; i >= 0; i--)
        printf("%.3f\n",sqrt(arr[i]));
}
