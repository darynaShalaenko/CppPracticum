#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


void f( string& s, char r, int n) {
    string temp = "";
    vector <string> words;
    for(char c: s){
        if(c != r){
            temp += c;
        }else if(temp.size() > 0){
            words.push_back(temp);
            temp = "";
        }
    }

    for(int i = 0; i < n; i++)
        cout << words[i] << " ";
}


int main() {
    string s = "adsda    yiyui zxccvxcv z poijlp    xcvvvcx  igy  ";
    f(s, ' ', 3);
    return 0;
}
