#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream input("TextFile1.txt");
    ofstream output("output.txt");
    string line;
    while (getline(input, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                output << line[i];
            }
        }
        output << ' ' << endl;
        
    }
    return 0;

}

