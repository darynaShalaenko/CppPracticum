#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


void f( string& s, char r) {
    string temp = "";
    int m = 0;
    double k = 0;
    double per = 0.0;
    vector <string> words;
    for(char c: s ){
        if(c != r) {
            temp += c;
            k += 1;
        }else if(temp.size() > 0){
            words.push_back(temp);
            temp = "";
        }
    }

    for(int i = 0; i < words.size(); i++){

        per = (m / k) * 100;
        m = 0;
        if ( i > 0 )
            cout << "Percents of word " << i   << " = " << per << endl;
        cout << endl;
        cout << words[i] << endl;
        for(int j = 0; j < words[i].size();j ++){

            cout << words[i][j] << " ";
            m += 1;
        }    

        per = (m / k) * 100;
        cout << " Percents of word " << i + 1 << " = " << per << endl;
    }    


}


int main() {
    string s = "Babyc vad an ";
    f(s, ' ');
    return 0;

} 
