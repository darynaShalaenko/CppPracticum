#include <iostream>
#include <deque>

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    deque <int> d;
    int x;
    while (cin >> x)
        d.push_back(x);
    

    while (d.size() > 2){
        d.pop_back();
        d.pop_front();
    }
    if (d.size() == 2){
        cout << d.front() << ' ' << d.back() << endl;
    } else{
        cout << d.back() << endl;
    }
}