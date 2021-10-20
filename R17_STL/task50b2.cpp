#include <iostream>
#include <string>
using namespace std;

int in() {
    int k;
    cout << "Enter k: ";
    cin >> k;
    return k;
}

string generateSequence(int k) {
    string res;
    for(int i = 1; res.size() <= k; i++) {
        res += to_string(i);
    }
    return res;
}

void out(char res) {
    cout << "res: " << res << endl;
}

int main() {
    int k = in();
    string n = generateSequence(k);
    out( n.at(k-1) );
    return 0;
}