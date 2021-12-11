
#incl
ude <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << '\n';
}

int main() {
    int data[] = {1,8,5,6,-4,3,4,0,9,7,2};
    int i=0;
    vector<int> m1,m2;
    while (data[i]>0){
        m1.push_back(data[i]);
        i++;
    }
    i++;

    while (i<(sizeof(data)/sizeof(*data))){
        m2.push_back(data[i]);
        i++;
    }



    priority_queue<int, vector<int>, greater<int>> q1(m1.begin(), m1.end()), q2(m2.begin(), m2.end());
    print_queue(q1);

    print_queue(q2);
    while(!q2.empty()) {
        q1.push(q2.top());
        q2.pop();
    }
    print_queue(q1);


