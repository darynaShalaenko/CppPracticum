
#include <iostream>
#include <string>
using namespace std;


void lineParsing(string line, string *words, int n, string delimiter) {
    int space;
    for (int i=0; i<n; i++) {
        space = line.find_first_of(delimiter);
        words[i] = line.substr(0, space);
        line.erase(0, space+1);
    }
}


int main() {
    string line = "good day today hello Hola moon sun";
    string delimiter = " ";
//    getline(cin, line);
//    cin >> delimiter;
    cout << line << endl;
    int n;
    cout << "n = ";
    cin >> n;
    string *words = new string[n];
    lineParsing(line, words, n, delimiter);
    for (int i=0; i<n; i++) {
        cout << words[i] << endl;
    }
    delete[] words;
}
