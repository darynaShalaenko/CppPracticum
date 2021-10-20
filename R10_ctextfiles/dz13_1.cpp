#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main()
{
    ifstream input("TextFile2.txt");
    ofstream output("Output.txt");
    string line;
    while (getline(input, line)) {
        for (int i = 0; i < line.size(); i++) {
            output << (char)toupper(line[i]);
        }
        output << endl;
    }
}

