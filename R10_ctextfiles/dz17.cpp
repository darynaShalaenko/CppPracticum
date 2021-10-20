#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file1("TextFile1.txt");
    string line;
    string word = "jhfkjf";
    string word2;
    int counter=0;
    while (getline(file1, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                word2 += line[i];
                if (word2 == word) {
                    counter++;
                }
            }
            else {
                word2 = "";
            }
        }


    }
    cout << counter;


}

