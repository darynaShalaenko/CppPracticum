#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector <int> a;
    while(n){
        a.push_back(n & 1);
        n /= 2;
    }
    int ans = 0;
    for (int i = 1; i < a.size(); i++)
        if (a[i] == a[i - 1] && a[i] == 1)
            ans++;
    cout << ans << endl;
}