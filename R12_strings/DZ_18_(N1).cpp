#include <iostream>
#include <string>

using namespace std;


int main() {
    string s;
    cin >> s;

    string new_s = "";

    for(char &c : s) {
        if (c == '.'){
            new_s += "...";
        } else if (c == '!') {
            new_s += '.';
        } else if (c == '*') {
            new_s += '+';
        } else {
            new_s += c;
        }
    }

    cout << new_s << endl;

    return 0;
}