//20.17

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;

template<class Container>
void print(const Container& a) {
    cout<<"["<<endl;
    for (const auto& item: a) {
        cout<<item<<endl;
    }
    cout<<"]"<<endl;
}

template<class Key, class Value>
ostream& operator<<(ostream& out, const pair<Key, Value>& p) {
    string psec="";
    for (int i=0; i<p.second.size(); i++) {
        psec+=to_string(p.second[i]);
        psec+=", ";
    }
    return out<<p.first<<": "<<psec;
}

bool contain(int num, vector<int> vct) {
    if (vct.size()!=0) {
        for (int i=0; i<vct.size(); i++) {
            if (vct[i]==num){
                return true;
            }
        }
    return false;
    }
    else {
        return false;
    }
}

map<int, vector<int>> grouping(vector<int> vct) {
    map<int, vector<int>> res;
    vector<int> used_num;
    for (int i=0; i<vct.size(); i++) {
        int digit=abs(vct[i])%10;
        for (int j=0; j<vct.size(); j++) {
            if (abs(vct[j])%10==digit) {
                if (!contain(vct[j],used_num)) {
                    res[digit].push_back(vct[j]);
                    used_num.push_back(vct[j]);
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> vct;
    int n;
    cout<<"Num of elements -> ";
    cin>>n;
    for (int i=0; i<n; i++) {
        int el;
        cin>>el;
        vct.push_back(el);
    }
    print(grouping(vct));
    return 0;
}