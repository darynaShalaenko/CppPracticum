#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int check(int n){
    return n & 1;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    cout << check(n) << endl;
}