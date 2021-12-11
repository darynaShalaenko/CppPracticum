#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    freopen ("input.txt","r",stdin);
    vector <double> a;
    double x;
    while (cin >> x)
        a.push_back(x);
    

    if (a.size() >= 2)
        cout << a[a.size() - 2] << endl;
    else
        cout << "NO ANSWER\n";
    
}