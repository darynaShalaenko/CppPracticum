#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    if (__builtin_popcount(n) == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    
}