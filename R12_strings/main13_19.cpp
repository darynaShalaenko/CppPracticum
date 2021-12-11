
#include <iostream>
#include <string>
using namespace std;

string chen(string s){
    string M1[27]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","A"};
    char M2[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'};
    string m1[27]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a"};
    char m2[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a'};
    for (size_t i=0; i<=s.size(); i++) {
        for(int j=0;j<26;j++){
            if(M2[j]==s[i]){
                s.replace(i, 1, M1[j+1]);
                //cout<<s<<endl;
                break;
            }
            if(m2[j]==s[i]){
                s.replace(i, 1, m1[j+1]);
                break;
            }
        }
    }
    return s;
}

void inchen(string &s){
    string M1[27]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","A"};

    char M2[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'};
    string m1[27]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a"};
    char m2[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a'};
    for (size_t i=0; i<=s.size(); i++) {
        for(int j=0;j<26;j++){
            if(M2[j]==s[i]){
                s.replace(i, 1, M1[j+1]);
                break;
            }
            if(m2[j]==s[i]){
                s.replace(i, 1, m1[j+1]);
                break;
            }
        }
    }
}


int main() {
    string text="FHGGbbFGHJT  FGDVTzzzzKJGCV  BGGMHFBJaaBBVNH";

    cout<<text<<endl<<chen(text)<<endl;
    inchen(text);
    cout<<text<<endl;
    return 0;
}
