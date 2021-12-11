
#include  <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int isInteger(const string & s){
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return 0;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

string toBinary(const string s){
    int n = atoi(s.c_str());
    string number;

    bool negative = (n < 0);
    if (negative)
        n = -n;
    do
    {
        number += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);

    if (negative)
        number += '-';
    return string(number.crbegin(), number.crend());
}


int main (){
    string filename = "file.txt";

    ifstream fin(filename);
    if (!fin.good()) exit(1);
    string line, ss;
    vector<vector<string>> v1;
    while (getline(fin, line)){
        vector<string> v2;
        for(int i = 0; i < line.size(); i++){
            if (line[i] != ' ') ss += line[i];
            if (line[i] == ' ' || i == line.size()-1){
                v2.push_back(ss);
                ss = "";
            }
        }
        v1.push_back(v2);
    }
    fin.close();
    cout << endl;
    for(int i = 0; i < v1.size(); i++){
        for (int j = 0; j < v1[i].size(); j++){
            if (isInteger(v1[i][j]))
                v1[i][j] = toBinary(v1[i][j]);
        }
    }

    ofstream fout(filename);
    if (!fout.good()) exit(1);
    else{
        for(auto i: v1){
            for (auto j: i)
                fout << j << " ";
            fout << endl;
        }
    }
    v1.clear();
    fout.close();
    return 0;
}
