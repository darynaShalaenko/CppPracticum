#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector <string> words;
    map <string, int> list;
    string s;

    ifstream file("text.txt");

    while (getline(file, s)) {
        istringstream ist(s);
        string tmp;
        while (ist >> tmp)
            words.push_back(tmp);
    }

    for (int i = 0; i < words.size(); i++) {
        string delim = " ,.?!;";
        for (int j = 0; j < delim.length(); j++) {
            if (words[i][words[i].length() - 1] == delim[j])
                words[i].resize(words[i].size() - 1);
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string temp = words[i];
        int count = 1;
        for (int j = i + 1; j < words.size(); j++) {
            if (words[j] == temp) count++;
        }
        list.insert(pair <string, int>(temp, count));
    }

    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    file.close();
    return 0;
}