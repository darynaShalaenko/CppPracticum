#include <iostream>
#include <vector>

using namespace std;

vector <string> Split(string s, int n, char c){
    string temp = "";
    int i = 0;
    vector <string> ans;
    while (i < s.size() && ans.size() < n){
        if (s[i] == c){
            if (temp.size())
                ans.push_back(temp);
            temp = "";
        } else
            temp += s[i];
        i++;
    }
    if (ans.size() < n && temp.size())
        ans.push_back(temp);
    return ans;
}

int main(){
    string s;
    int n;
    char c;
    cout << "string = ";
    getline(cin, s);
    cout << "n = ";
    cin >> n;
    cout << "char = ";
    cin >> c;

    vector <string> ans = Split(s,n,c);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}