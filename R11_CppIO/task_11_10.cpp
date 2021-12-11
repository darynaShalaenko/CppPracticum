
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    string line, temp = "";
    vector<int> v;
    ifstream F;
    F.open("input.txt", ios::in);
    while (getline(F, line)) {
        for (char c : line + " ") {
            if (isdigit(c) || c == '-' || c =='+') {
                temp += c;
            } else if (temp.size() > 0) {
                v.push_back(atoi(temp.c_str()));
                temp = "";
            }
        }
    }
    F.close();

    ofstream G;
    G.open("output.txt", ios::out);
    for (int i : v) {
        if (i >= 0)
            G << i << " ";
    }
    G.close();
    return 0;
}
