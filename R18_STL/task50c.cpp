#include <iostream>
#include <vector>
using namespace std;

int in() {
    int k;
    cout << "Enter k: ";
    cin >> k;
    return k;
}

vector<int> numberToVector(int n) {
    vector<int> res;
    while(n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

vector<int> generateSequence(int k) {
    vector<int> res;
    for(int i = 1; res.size() <= k; i++) {
        vector<int> t = numberToVector(i*i);
        for(int j = (t.size() - 1); j > -1; j--) {
            res.push_back( t.at(j) );
        }
    }
    return res;
}

void out(int res) {
    cout << "res: " << res << endl;
}

int main() {
    int k = in();
    vector<int> n = generateSequence(k);
    out( n.at(k-1) );
    return 0;
}