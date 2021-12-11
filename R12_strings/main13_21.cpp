
#include <iostream>
#include <string>
using namespace std;

string words21(string s, string del){
    size_t pos=0;
    if(s[s.size()-1]!=' '){
        s=s+" ";
    }
    string a;
    char b;
    while ((pos=s.find(del))!=string::npos) {
        string word=s.substr(0,pos);
        s.erase(0,pos+del.length());
        if(word.size()<2){
            a=a+word+" ";
        }
        else{
            b=word[word.size()-2];
            for (int i = 0; i < word.size() - 1; ++i){
                if(b==word[i]){
                    word.replace(i, 1, "");
                    i--;
                }
            }
            a=a+word+" ";
        }
    }
    return a;
}

int main() {
    string text="vfglglfgl     bnjmkl  sccdcd  shc";
    //getline(cin, text);
    cout<<text<<endl;
    cout<<words21(text," ");
    return 0;
}
