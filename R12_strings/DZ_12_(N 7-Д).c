#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector<string> readFile(const string fName) {
    vector<string> res;
    ifstream in;
    in.open(fName);
    string buff;

    while (getline(in, buff)) {
        res.push_back(" " + buff + " ");
    }
    in.close();

    return res;

}

vector<string> gatherWords(string s) {
    int start = -1;
    int cnt = 0;
    bool flag = false;
    vector<string> res;

    for(int i = 0; i < s.length() - 1; ++i) {
        if(s[i] == ' ' && s[i+1] != ' ') {
            start = i;
            flag = true;
        }
        if (flag) {
            cnt++;
        }

        if(s[i] != ' ' && s[i+1] == ' ' && flag) {
            flag = false;
            res.push_back(s.substr(start, cnt));
            cnt = 0;
        }
    }
    return res;
}

int charNum(vector<string> v) {
    int res = 0;
    for(auto word:v)
        res += word.length();

    return res;
}

string processLine(string s) {
    vector<string> temp = gatherWords(s);
    int iter = 0;
    int cnt = charNum(temp);
    while(cnt != 80){
        temp[iter%(temp.size() - 1)] += " ";
        cnt++;
        iter++;
    }
    string res = "";
    for(auto word:temp) {
        res += word;
    }

    return res;
}

void writeFile(const string fName, string data) {
    ofstream out(fName);
    out << data;
    out.close();
}


int main() {
    vector<string> buff;
    buff = readFile("in1.txt");
    string res = "";
    for (auto s:buff)
        res += processLine(s) + "\n";
    writeFile("out2.txt", res);

    return 0;
}