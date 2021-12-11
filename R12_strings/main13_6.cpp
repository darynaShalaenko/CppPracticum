#include <iostream>
#include <string>
using namespace std;

int split(string s, string delim,int n, string words[]){
    size_t pos=0;
    size_t k=0;
    if(s[s.size()-1]!=' '){
        s=s+" ";
    }
    while ((pos=s.find(delim))!=string::npos && k<n) {
        words[k++]=s.substr(0,pos);
        s.erase(0,pos+delim.length());
    }
    return k;
}

int main() {
    string text="Write your code in this editor and press button to compile and execute it";
    string delim=" ";
    string words[14];
    int m =split(text,delim, 15, words);
    for(int i=0;i<m;i++){
        cout<<words[i]<<endl;
    }
    return 0;
}
