#include <iostream>
#include <vector>
using namespace std;

int in() {
    int k;
    cout << "Enter k: ";
    cin >> k;
    return k;
}

vector<int> fib = {0, 1};
int fibonacci(int n) {
    if(n >= fib.size()) {
        for(int i = fib.size(); i <= n; i++) {
            fib.push_back( fib.at(i-1) + fib.at(i-2) );
        }
    }
    return fib.at(n);
}

vector<int> numberToVector(int n) {
    if(n == 0) return {0};
    vector<int> res;
    while(n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

vector<int> generateSequence(int k) {
    vector<int> res;
    for(int i = 0; res.size() <= k; i++) {
        vector<int> t = numberToVector( fibonacci(i) );
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