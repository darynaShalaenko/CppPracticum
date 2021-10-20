#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string readFile(const string fName) {
    string res = "";
    ifstream in;
    in.open(fName);
    string buff;

    while (in >> buff) {
        res += buff + "\n";
    }
    in.close();

    return res;

}

string lower(string data) {
    string res = "";
    for(int i = 0; i < data.length(); ++i) {
        res += tolower(data[i]);
    }
    return res;
}

string reverse(string data) {
    string res = "";
    for(int i = data.length(); i >= 0; --i) {
        res += data[i];
    }
    return res;
}


void writeFile(const string fName, string data) {
    ofstream out(fName);
    out << data;
    out.close();
}


int main() {
    string buff;
    buff = readFile("in1.txt");
    writeFile("out1.txt", lower(buff));
    writeFile("out2.txt", reverse(buff));
    return 0;
}