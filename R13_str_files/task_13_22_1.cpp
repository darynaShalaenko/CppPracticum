
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string next(string subs, char r) {
    string temp = "";
    for(char c: subs){
        if(c != r){
            temp += c;
        }else if(temp.size() > 0){
            return temp;
        }
    }
}

string prev(string subs, char r) {
    reverse(subs.begin(),subs.end());
    string temp=next(subs,r);
    reverse(temp.begin(),temp.end());
    return temp;
}





void findd( string& s, char r, string sub1, string sub2) {
    while (s.find(sub1)!=-1){
        int i=s.find(sub1);
        string x=prev(s.substr(0,i),r), y=next(s.substr(i+sub1.size()),r);
        string temp=y+sub2+x;
        cout<<s.substr(0, s.find(x))+temp;
        s=s.substr(s.find(y)+y.size());
    }
    cout<<s;
}




int main() {
    string s="jewwe's eioe ejel's jwenfi";
    findd(s,' ',"'s", " of ");
    return 0;
