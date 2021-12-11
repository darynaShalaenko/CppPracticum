#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    freopen ("input.txt","r",stdin);
    vector <string> a;
    string s;
    while (cin >> s){
        a.push_back(s);
    }
    int max_len = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i].size() > max_len)
            max_len++;
    for (int i = 0; i < a.size(); i++)
        if (a[i].size() == max_len)
            cout << a[i] << ' ';
    cout << endl;
    
}