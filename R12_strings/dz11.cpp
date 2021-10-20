#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count=0;
    map<char,int> res;
    int t = 0;
    for (int i = 0; i < s.size()-1; i++) {
        for (int j = 1; j < s.size() - i; j++) {
            if (s[i] == s[i + j]) {
                res[i] += 1;
            }
            else { break; }
        }
 
    }
    int result=0;
    char res_char;
    for (auto i = 0; i < res.size(); i++) {
        if (result <= res[i]) {
            result = res[i];
        }
    }
    
    cout << result + 1<<endl;
}

