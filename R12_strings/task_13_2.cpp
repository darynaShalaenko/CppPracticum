include <iostream>
#include <string>
using namespace std;

string f( string& s){
    int pos1 = s.find(".");
    int pos2 = s.rfind(".");
    int i = 0;
    if ((pos1 > -1 && pos2 > -1) && (pos1 != pos2)){
        int riz = pos2 - pos1;
        return s.erase(pos1,riz + 1);
    }else
        if(pos1 == pos2){
            int pos = s.find(".");
            return s.erase(0, pos);
        }
        else{
            for(char c: s){
                i += 1;
                if (c != ' ')
                    break;
            }
               return s.erase(0, i - 1);    
        }
}



int main(){
    string s = " 1234 abc abc bca  123. ";
    cout << f(s) << endl;

    return 0;
} 
