#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    int max_el = a[0];
    for (int i = 0; i < n; i++)
        max_el = max(max_el, a[i]);
    
    map<int,int> fibb;
    int f1 = 0, f2 = 1;
    fibb[f1] = 1;
    fibb[f2] = 1;
    while (f2 < max_el){
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        fibb[f3] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (fibb[a[i]])
            ans++;
    cout << ans << endl;
}