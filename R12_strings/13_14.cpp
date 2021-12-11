#include <iostream>

using namespace std;

int main(){
    string s;
    cout << "string = ";
    getline(cin, s);
    char c;
    cout << "char = ";
    cin >> c;
    string temp = "";
    int i = 0;
    bool ok = false;
    int ans = 0;
    while (i < s.size()){
        if (s[i] == ' '){
            if (ok && temp.size())
                ans ++;
            ok = false;
            temp = "";
        } else{
            temp += s[i];
            if (s[i] == c)
                ok = true;
        }
        i++;
    }
    if (ok && temp.size())
        ans ++;
    cout << ans << endl;
}