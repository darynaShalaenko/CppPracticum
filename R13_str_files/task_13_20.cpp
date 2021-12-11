#include <iostream>
#include <string>
using namespace std;


void findd(string& s, string strn, string n) {
    while (s.find(strn)!=-1){
        s.replace(s.find(strn),strn.size(),n);
    }
}


int main() {
    string s="woeifoneiewfwothree ifdweofmew wkefo four wef wkjednw wkldn";
    findd(s,"one","1");
    findd(s,"two","2");
    findd(s,"three","3");
    findd(s,"four","4");
    findd(s,"five","5");
    findd(s,"six","6");
    findd(s,"seven","7");
    findd(s,"eight","8");
    findd(s,"nine","9");
    cout<<s;
}
