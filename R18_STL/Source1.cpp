#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


bool prompt(const string& p) {
    string answ;
    cout << p << " (yes/no): ";
    cin >> answ;
    return (answ[0] == 'y' || answ[0] == 'Y');
}

bool cmpNoCase(const string& a, const string& b) {
    string::const_iterator i, j;
    for (i = a.begin(), j = b.begin(); i != a.end() && j != b.end(); ++i, ++j) {
        if (tolower(*i) < tolower(*j))
            return true;
        else if (tolower(*i) > tolower(*j))
            return false;
    }
    return (a.length() < b.length());
}

int main() {
    string file_name;
    cout << "Name of input file: ";
    cin >> file_name;
    ifstream ifs(file_name.c_str());
    if (!ifs.is_open()) {
        cerr << "Can't open file <" << file_name << "> for input!" << endl;
        return 1;
    }

    list<string> strings;
    string buf;
    while (ifs >> buf) {
        while (ispunct(*(buf.end() - 1)))
            buf.erase(buf.end() - 1);
        strings.push_back(buf);
    }
    if (ifs.bad()) {
        cerr << "Can't read input file!" << endl;
        return 1;
    }
    ifs.close();

    strings.unique();
    strings.sort(cmpNoCase);
    copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));

    bool has_new_words = false;
    while (prompt("Add a new word?")) {
        has_new_words = true;
        cout << "New word: ";
        cin >> buf;
        while (ispunct(*(buf.end() - 1)))
            buf.erase(buf.end() - 1);
        strings.push_back(buf);
    }

    if (has_new_words) {
        cout << "New words list:" << endl;
        strings.unique();
        strings.sort(cmpNoCase);
        copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));
    }

    if (prompt("Save to file?")) {
        cout << "Name for output file: ";
        cin >> file_name;
        ofstream ofs(file_name.c_str());
        if (!ofs.is_open()) {
            cerr << "Can't open file <" << file_name << "> for output!" << endl;
            return 1;
        }
        copy(strings.begin(), strings.end(), ostream_iterator<string>(ofs, "\n"));
        if (ofs.bad()) {
            cerr << "Can't write to output file!" << endl;
            return 1;
        }
        ofs.close();
        cout << "Done." << endl;
    }

    return 0;
}